import json

import asyncio
from main.request import Request
from main.builder import Builder
from main.writer import Writer


# CDI = 12
# IGP-M = 189
# IGP-DI = 190


async def handler(payload):
    res = await Request(payload).handler()
    df = await Builder(res, payload).handler()
    await Writer(df, payload).handler()


with open("series.json") as e:
    event = json.load(e)


loop = asyncio.new_event_loop()
loop.run_until_complete(handler(event))
