import pandas as pd


class Builder:

    def __init__(self, result, payload):
        self.result = result
        self.payload = payload

    @staticmethod
    async def build_prices_from_returns(df):
        cols = ["date", "close_price"]
        df["date"] = pd.to_datetime(df["data"], format="%d/%m/%Y")
        df["date"] = df["date"].dt.strftime("%Y-%m-%d")
        df["ret"] = df["valor"].astype(float) / 100
        df["close_price"] = df["ret"].add(1).cumprod().mul(1e-3)
        return df[cols]

    async def handler(self):
        df = pd.DataFrame(self.result)
        res = await getattr(self, f"build_{self.payload['resultBuilder']}")(df)
        return res