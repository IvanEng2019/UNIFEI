import re
import asyncio
from io import BytesIO

from s3fs import S3FileSystem

s3_pattern = re.compile(r"(s3:\/\/(?P<bucket>.*?(?=\/))\/(?P<path>.*?.*))")


class S3:
    def __init__(self):
        self.session = None

    async def __aenter__(self):
        s3 = S3FileSystem(asynchronous=True,
                          loop=asyncio.get_running_loop())
        self.session = await s3.set_session(refresh=True)
        return self

    async def __aexit__(self, exc_type, exc_val, exc_tb):
        print("Process ended")

    async def get_file(self, path):
        match = s3_pattern.match(path)
        file = await self.session.get_object(Bucket=match["bucket"], Key=match["path"])
        return BytesIO(await file["Body"].read())

    async def insert_file(self, file, path):
        match = s3_pattern.match(path)
        await self.session.put_object(Bucket=match["bucket"], Key=match["path"], Body=file)