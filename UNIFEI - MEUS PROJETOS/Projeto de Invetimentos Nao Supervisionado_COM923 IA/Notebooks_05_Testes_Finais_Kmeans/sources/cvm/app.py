import os
import json
import asyncio
from io import BytesIO
import re

from crawler import Crawler
from builder import Builder
from aws.s3 import S3


proxy_source = "https://www.sslproxies.org/"
base_path = os.path.dirname(os.path.abspath(__file__))
BUCKET_NAME = os.environ.get("BUCKET", "ira-raw-data-market")
LOCAL_PATH = "E:\\data-science\\raw-data"
LOCAL = True



class Loader:
    def __init__(self, schema, args):
        self.schema = json.load(open(os.path.join(base_path, "plans/catalog.json"), encoding="utf8")).get(schema)

    @staticmethod
    def quarterly_results_path_map(name):
        itr = re.sub("[^A-Z]", "", name)
        return f"{itr}/{name}"

    @staticmethod
    def simple_path_map(name):
        return name

    @staticmethod
    def year_path_map(name):
        return name

    def prepare_result(self, result):
        res = list()
        for df in result:
            path = f"{self.schema['path']}/{getattr(self, self.schema['map_path'])(df.index.name)}"
            s3_path = f"s3://{BUCKET_NAME}/cvm/{path}.csv"
            buffer = BytesIO()
            df.to_csv(buffer, index=False)
            res.append((buffer, s3_path))
        return res

    @staticmethod
    def build_chunks(slots):
        chunk_size = 5
        return [slots[i:i + chunk_size] for i in range(0, len(slots), chunk_size)]

    async def save_local(self, result):
        for df in result:
            path = f"{self.schema['path']}/{getattr(self, self.schema['map_path'])(df.index.name)}"
            full_path = f"{LOCAL_PATH}/cvm/{path}.csv"
            print(f"SAVING {full_path}")
            try:
                df.to_csv(full_path, index=False)
            except FileNotFoundError:
                os.makedirs(full_path.rsplit('/', 1)[0])
                df.to_csv(full_path, index=False)

    @staticmethod
    async def save_data(chunks):
        for chunk in chunks:
            async with S3() as s3:
                tasks = list()
                for buffer, s3_path in chunk:
                    print(f"[RUNNING] TASK - {s3_path}")
                    tasks.append(s3.insert_file(buffer.getvalue(), s3_path))
                await asyncio.gather(*tasks)

    async def load(self, args):
        function = f"{self.schema['process']}_loader"
        print(f"[STARTING] {function}")
        result = await getattr(self, function)(args)
        print(f"[SUCCESS] RESULTS PROCESSED")
        print(f"[RUNNING] PREPARING RESULTS")
        if LOCAL:
            await self.save_local(result)
        else:
            slots = self.prepare_result(result)
            print(f"[RUNNING] SAVING RESULTS")
            chunks = self.build_chunks(slots)
            await self.save_data(chunks)
            print(f"[SUCCESS] ALL FILES SAVED")

    async def full_loader(self, args):
        data = Crawler(proxy_source=proxy_source, url=self.schema["url"]).zip_crawl()
        return data

    async def simple_loader(self, args):
        data = Crawler(proxy_source=proxy_source, url=self.schema["url"]).crawl()
        # results = Builder(data).architect
        return data

    async def yearly_loader(self, args):
        res = list()
        for month in range(1, 13):
            url = f"{self.schema['url']}{args['year']}{str(month).zfill(2)}.zip"
            print(url)
            data = Crawler(proxy_source=proxy_source, url=url).zip_crawl()
            res.extend(data)
        # results = Builder(data).architect
        return res

    async def monthly_loader(self, year, month):
        url = f"{self.schema['url']}{year}{month}.csv"
        data = Crawler(proxy_source=proxy_source, url=url)
        # results = Builder(data).architect.crawl()
        return data


async def handler(event):
    results = await Loader(event["schema"], {}).load(event["args"])


def lambda_handler(event, context):
    loop = asyncio.get_event_loop()
    loop.run_until_complete(handler(event))
    loop.close()


event = {
    "schema": "funds-lamina",
    "args": {
        "year": ""
    }
}

# for year in range(2012, 2022):
#     event["year"] = year
lambda_handler(event, "")
