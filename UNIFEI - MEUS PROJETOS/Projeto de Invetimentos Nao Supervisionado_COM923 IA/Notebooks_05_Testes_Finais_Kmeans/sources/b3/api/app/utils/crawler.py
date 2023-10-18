import io
import json
from base64 import b64encode
from zipfile import ZipFile

import requests
import pandas as pd
from retrying import retry
from fake_useragent import UserAgent


def retry_errors(exception):
    return isinstance(exception, AttributeError) or isinstance(exception, pd.errors.EmptyDataError)


class Crawler:
    def __init__(self, url, txt_field_length=None):
        self.ua = UserAgent()
        self.url = url
        self.field_length = txt_field_length
        self.errors = list()

    @staticmethod
    def target_path(payload):
        return b64encode(str(payload).encode("utf-8")).decode("utf-8")

    # @retry(retry_on_exception=retry_errors, stop_max_attempt_number=10)
    def json_crawl(self, payload=dict(), result=pd.DataFrame()):
        print(payload, self.url)
        try:
            data = requests.get(self.url, headers={"User-Agent": self.ua.random}, verify=False).json()
            if data.get("page"):
                if payload["pageNumber"] <= data["page"]["totalPages"]:
                    df = pd.DataFrame(data["results"])
                    result = pd.concat([result, df])
                    payload["pageNumber"] += 1
                    p = self.url.split('/')[-1]
                    self.url = f"{self.url.replace(p, '')}{self.target_path(payload)}"
                    return self.json_crawl(payload, result)
                else:
                    return result
            else:
                result = pd.DataFrame([data])
        except json.decoder.JSONDecodeError:
            self.errors.append(payload)
            return result
        return result

    def generate_df(self, file, name):
        if self.field_length:
            data = pd.read_fwf(filepath_or_buffer=file, widths=self.field_length, header=0, encoding="iso8859-1")
        else:
            data = pd.read_fwf(filepath_or_buffer=file, sep=";", encoding="iso8859-1")
        data.index.name = name.split("_")[0].lower().replace("-", "").split(".")[0]
        return data

