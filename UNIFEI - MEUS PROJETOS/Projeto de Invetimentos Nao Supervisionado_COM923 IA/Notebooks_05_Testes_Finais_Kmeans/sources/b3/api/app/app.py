import os
import json
from base64 import b64encode
import asyncio
from io import BytesIO
import pandas as pd

from utils.crawler import Crawler
from aws.s3 import S3



base_path = os.path.dirname(os.path.abspath(__file__))


BUCKET_NAME = os.environ.get("BUCKET", "ira-raw-data-market")
LOCAL_PATH = "E:\\data-science\\raw-data"
LOCAL = True


class Loader:
    def __init__(self, schema, args):
        self.catalog = json.load(open(os.path.join(base_path, "plans/catalog.json"), encoding="utf8"))
        self.schema = self.catalog.get(schema)
        self.args = args

    async def save_local(self, result):
        for df in result:
            path = f"{self.schema['path']}/{getattr(self, self.schema['map_path'])(df.index.name)}"
            full_path = f"{LOCAL_PATH}/b3/{path}.csv"
            print(f"SAVING {full_path}")
            df.to_csv(full_path, index=False)

    @staticmethod
    async def save_data(data):
        tasks = list()
        async with S3() as s3:
            for buffer, s3_path in data:
                print(f"[RUNNING] TASK - {s3_path}")
                tasks.append(s3.insert_file(buffer.getvalue(), s3_path))
            await asyncio.gather(*tasks)

    @staticmethod
    def default_path_map(name):
        return name

    def prepare_result(self, result):
        res = list()
        for df in result:
            path = f"{self.schema['path']}/{getattr(self, self.schema['map_path'])(df.index.name)}"
            s3_path = f"s3://{BUCKET_NAME}/b3/{path}.csv"
            buffer = BytesIO()
            df.to_csv(buffer, index=False)
            res.append((buffer, s3_path))
        return res

    @staticmethod
    def target_path(payload):
        return b64encode(str(payload).encode("utf-8")).decode("utf-8")

    @staticmethod
    def explode_df(df, target_col):
        df = df.explode(target_col).reset_index().drop(columns="index")
        df = df.join(pd.json_normalize(df[target_col]))
        df.pop(target_col)
        return df

    async def get_listed_companies(self, cat):
        schema = self.catalog[cat]
        url = f"{schema['url']}/{self.target_path(schema['payload'])}"
        results = Crawler(url=url).json_crawl(payload=schema["payload"])
        return results

    async def general_loader(self, target=None, payload=None):
        url = target if target else f"{self.schema['url']}/{self.target_path(self.schema['payload'])}"
        print(url)
        payload = payload if payload else self.schema["payload"]
        raw_results = Crawler(url=url).json_crawl(payload=payload)
        raw_results.index.name = self.schema["path"]
        return [raw_results]

    async def traded_companies_info_loader(self):
        result = pd.DataFrame()
        target = "bdr-companies-info" if self.schema["path"] == "bdr-companies-info" else "traded-companies-info"
        raw_results = await self.get_listed_companies(target)
        cvm_codes = list(raw_results["codeCVM"].unique())
        for cvm_code in cvm_codes:
            target = self.catalog["single-traded-company-info"]
            target["payload"]["codeCVM"] = cvm_code
            target["payload"]["pageNumber"] = 1
            url = f"{target['url']}/{self.target_path(target['payload'])}"
            df = (await self.general_loader(target=url, payload=target))[0]
            result = pd.concat([result, df])
        result.index.name = "traded_companies_info"
        return [result]

    async def traded_companies_dividends_loader(self):
        raw_results = (await self.get_listed_companies())[["codeCVM", "cnpj", "tradingName"]]
        names = list(raw_results["tradingName"].unique())
        for name in names:
            target = self.catalog["single-traded-company-dividends"]
            target["payload"]["tradingName"] = name
            target["payload"]["pageNumber"] = 1
            url = f"{target['url']}/{self.target_path(target['payload'])}"
            df = (await self.general_loader(target=url, payload=target["payload"]))[0]
            df["tradingName"] = name
            print(df)
            if not df.empty:
                result = df.merge(raw_results, on="tradingName", how="left")
                result.index.name = name
                if LOCAL:
                    await self.save_local([result])
                else:
                    slots = self.prepare_result([result])
                    await self.save_data(slots)

    async def load(self):
        function = f"{self.schema['process']}_loader"
        print(f"[STARTING] {function}")
        result = await getattr(self, function)()
        if self.schema['process'] == "traded_companies_dividends":
            return
        print(f"[SUCCESS] RESULTS PROCESSED")
        print(f"[RUNNING] PREPARING RESULTS")
        if LOCAL:
            await self.save_local(result)
        else:
            slots = self.prepare_result(result)
            print(f"[RUNNING] SAVING RESULTS")
            await self.save_data(slots)
            print(f"[SUCCESS] ALL FILES SAVED")



async def handler(event):
    await Loader(event["schema"], event["args"]).load()


def lambda_handler(event, context):
    loop = asyncio.get_event_loop()
    loop.run_until_complete(handler(event))
    # loop.close()


event = {
    "schema": "bdr-companies-info",
    "args": {}
}


lambda_handler(event, "")
