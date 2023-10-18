import json
import pandas as pd


class Builder:
    def __init__(self, dfs):
        self.dfs = dfs
        self.bool_mask = {"S": True, "N": False}
        self.names = json.load(open("./plans/names.json"))
        self.types = json.load(open("./plans/types.json"))

    @property
    def architect(self):
        if isinstance(self.dfs, list):
            result = pd.concat([self.build(df) for df in self.dfs])
        else:
            result = self.build(self.dfs)

        results = list()
        for k, v in result.groupby("cvm_code"):
            for n, d in v.groupby("itr_type"):
                df = d.sort_index()
                df.index.name = f"{df.index.name}-{k}-{n}"
                results.append(df)
        return results

    @staticmethod
    def name_constructor(name):
        documents = ("cad_fi", "inf_diario_fi", "cad_cia_aberta", "itr_cia_aberta")
        for doc in documents:
            if doc in name:
                return doc
        raise ValueError("Unexpected document")

    def piper(self, name):
        _name = self.name_constructor(name)
        _pipes = {
            "cad_fi": "investment_funds_info",
            "inf_diario_fi": "investment_funds_prices",
            "cad_cia_aberta": "companies_info",
            "itr_cia_aberta": "companies_itr"
        }
        return _pipes.get(_name)

    @staticmethod
    def investment_funds_info(df):
        return df

    @staticmethod
    def investment_funds_prices(df):
        df["cnpj"] = df["cnpj"].str.replace(r"\D+", "")
        df["date"] = pd.to_datetime(df["date"])
        return df

    @staticmethod
    def companies_info(df):
        return df

    def companies_itr(self, df):
        df = df.iloc[1:, :]
        if "exercise_order" in df.columns:
            df = df.loc[df["exercise_order"] == "ÚLTIMO"]
            df["multiplier"] = df["multiplier"].replace({"MIL": 1000, "UNIDADE": 1}).astype("int64")
            df["final_value"] = df["multiplier"] * df["value"]
            cols = [col for col in self.names["filtered_itr"] if col in df.columns]
            df = df[cols]
        return df

    def build(self, df):
        name = df.index.name
        piper = self.piper(name)

        col_names = self.names[piper]
        col_types = {key: self.types[piper][key] for key in df.columns}

        df = df.replace(self.bool_mask).astype(col_types).rename(columns=col_names)
        df = df[list(set(col_names.values()).intersection(df.columns))]

        return df.pipe(getattr(self, piper))
