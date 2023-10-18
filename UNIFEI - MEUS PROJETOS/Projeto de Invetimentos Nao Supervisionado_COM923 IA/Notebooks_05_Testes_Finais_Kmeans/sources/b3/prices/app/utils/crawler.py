import io
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

    @retry(retry_on_exception=retry_errors, stop_max_attempt_number=10)
    def zip_crawl(self):
        results = list()
        data = requests.get(self.url, headers={"User-Agent": self.ua.random}, verify=False).content
        zip_file = ZipFile(io.BytesIO(data))
        for txt in zip_file.namelist():
            results.append(self.generate_df(zip_file.open(txt), txt))
        return results

    def generate_df(self, file, name):
        if self.field_length:
            data = pd.read_fwf(filepath_or_buffer=file, widths=self.field_length, header=0, encoding="iso8859-1")
        else:
            data = pd.read_fwf(filepath_or_buffer=file, sep=";", encoding="iso8859-1")
        data.index.name = name.split("_")[0].lower().replace("-", "").split(".")[0]
        return data

