


class Writer:

    def __init__(self, result, payload):
        self.result = result
        self.payload = payload

    @staticmethod
    def csv_formatter(df, destination):
        return df.to_csv(destination, index=False)

    async def handler(self):
        res = getattr(self, f"{self.payload['format']}_formatter")(self.result, self.payload["destination"])