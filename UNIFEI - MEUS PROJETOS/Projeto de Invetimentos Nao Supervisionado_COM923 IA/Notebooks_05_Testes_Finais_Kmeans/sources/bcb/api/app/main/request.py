from aiohttp import ClientSession


BASE_URL = "http://api.bcb.gov.br"


class Request:

    def __init__(self, payload):
        self.payload = payload

    @staticmethod
    async def get(url):
        async with ClientSession() as session:
            response = await session.get(url=url)
            response.raise_for_status()
            return await response.json()

    @staticmethod
    def series_url(args):
        return f"{BASE_URL}/dados/serie/bcbdata.sgs.{args['id']}/dados?formato=json"

    async def handler(self):
        url = getattr(self, self.payload["urlBuilder"])(self.payload["args"])
        result = await getattr(self, self.payload["requestType"])(url)
        return result