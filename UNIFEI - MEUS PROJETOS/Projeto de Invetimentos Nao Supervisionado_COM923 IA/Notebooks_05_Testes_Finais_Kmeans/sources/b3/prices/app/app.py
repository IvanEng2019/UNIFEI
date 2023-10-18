import os
import json
import asyncio
from io import BytesIO
import pandas as pd

from cryptography.fernet import Fernet

from utils.crawler import Crawler
from utils.builder import Builder
from aws.s3 import S3


# https://www.b3.com.br/data/files/C8/F3/08/B4/297BE410F816C9E492D828A8/SeriesHistoricas_Layout.pdf
# https://www.b3.com.br/data/files/4F/91/A8/CD/2A280710E7BCA507DC0D8AA8/TradeIntradayFile.pdf
base_path = os.path.dirname(os.path.abspath(__file__))


BUCKET_NAME = os.environ.get("BUCKET", "ira-raw-data-market")
LOCAL_PATH = "E:\\data-science\\raw-data"
LOCAL = True


class Loader:
    def __init__(self, schema, args):
        self.schema = json.load(open(os.path.join(base_path, "plans/catalog.json"), encoding="utf8")).get(schema)
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

    async def historical_quotes_loader(self):
        daily_field_length = [2, 8, 2, 12, 3, 12, 10, 3, 4, 13, 13, 13, 13, 13,
                              13, 13, 5, 18, 18, 13, 1, 8, 7, 13, 12, 3]
        url = f"{self.schema['url']}{self.args['year']}.ZIP"
        raw_results = Crawler(url=url, txt_field_length=daily_field_length).zip_crawl()
        results = Builder(dfs=raw_results, year=year).architect.sort_values("date")
        return [results]

    def historical_quotes_path_map(self, name):
        return f"{self.args['year']}"

    def prepare_result(self, result):
        res = list()
        for df in result:
            path = f"{self.schema['path']}/{getattr(self, self.schema['map_path'])(df.index.name)}"
            s3_path = f"s3://{BUCKET_NAME}/b3/{path}.csv"
            buffer = BytesIO()
            df.to_csv(buffer, index=False)
            res.append((buffer, s3_path))
        return res

    async def load(self):
        function = f"{self.schema['process']}_loader"
        print(f"[STARTING] {function}")
        result = await getattr(self, function)()
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
    "schema": "historical-quotes",
    "args": {
        "year": None
    }
}

start = 2000
end = 2022
for year in range(start, end + 1):
    event["args"]["year"] = year
    lambda_handler(event, "")
