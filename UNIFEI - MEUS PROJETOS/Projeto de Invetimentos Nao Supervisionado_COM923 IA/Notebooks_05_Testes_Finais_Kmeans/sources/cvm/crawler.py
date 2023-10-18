import io
import random
import requests
import re
import pandas as pd

import zipfile
from retrying import retry
from zipfile import ZipFile
from urllib.request import Request, urlopen
from fake_useragent import UserAgent


def retry_errors(exception):
    return isinstance(exception, AttributeError) or isinstance(exception, pd.errors.EmptyDataError)


class Crawler:
    def __init__(self, proxy_source=None, url=None):
        self.proxy_source = proxy_source
        # self.ua = UserAgent()
        # self.proxies = self.get_proxies()
        self.url = url

    def random_proxy(self):
        return self.proxies[random.randint(0, len(self.proxies) - 1)]

    def get_proxies(self):
        req = Request(self.proxy_source, headers={"User-Agent": self.ua.random})
        proxy = urlopen(req).read().decode("utf8")
        ips = re.findall(r'[0-9]+(?:\.[0-9]+){3}:[0-9]+', proxy)
        return [{"https": f"https://{ip}"} for ip in ips]

    def get_available_history(self):
        # req = Request(self.url, headers={"User-Agent": self.ua.random})
        req = Request(self.url, headers={"User-Agent": "Mozilla/5.0 (X11; Linux x86_64) AppleWebKit/537.36 (KHTML, like Gecko)"})
        data = urlopen(req).read().decode("windows-1252")
        files = re.findall('<a href="(.*?).zip">', data)
        return [f"{self.url}{file}.zip" for file in files] if files else [self.url]

    @staticmethod
    def csv_to_dataframe(data, name):
        if not isinstance(data, zipfile.ZipExtFile):
            data = io.StringIO(data)
        df = pd.read_csv(data, sep=";", low_memory=False, encoding="windows-1252", error_bad_lines=False)
        df.index.name = name.split(".")[0]
        return df

    @retry(retry_on_exception=retry_errors, stop_max_attempt_number=10)
    def csv_crawl(self):
        # data = requests.get(self.url, proxies=self.random_proxy()).text
        print(f"[RUNNING] {self.url}")
        data = requests.get(self.url)
        data.encoding = "windows-1252"
        res = data.text
        return self.csv_to_dataframe(res, self.url.split("/")[-1])

    @retry(retry_on_exception=retry_errors, stop_max_attempt_number=10)
    def zip_crawl(self):
        results = list()
        for zip_url in self.get_available_history():
            # data = requests.get(zip_url, proxies=self.random_proxy()).content
            data = requests.get(zip_url).content
            zip_file = ZipFile(io.BytesIO(data))
            results.extend([self.csv_to_dataframe(zip_file.open(_csv), _csv) for _csv in zip_file.namelist()])
        return results

    def crawl(self):
        if "csv" in self.url.split("."):
            return [self.csv_crawl()]
        return self.zip_crawl()
