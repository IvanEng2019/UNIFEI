import requests
from pypasser import reCaptchaV3
import pandas as pd

LOCAL_PATH = "E:\\data-science\\raw-data"

BASE_URL = "https://api2.apprendafixa.com.br/vn/get_featured_investments"

BASE_HEADERS = {
    "Contenty-Type": "application/json",
    "User-Agent": "Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/105.0.0.0 Safari/537.36",
    "Referer": "https://www.apprendafixa.com.br/"
}

BASE_PAYLOAD = {
    "idx": [],
    "corretora": [],
    "emissor": []
}

ANCHOR_URL = "https://www.google.com/recaptcha/api2/anchor?ar=1&k=6LdsVjsdAAAAAB8_v0h38z53yEDL_QYcs7TGB_9E&co=aHR0cHM6Ly93d3cuYXBwcmVuZGFmaXhhLmNvbS5icjo0NDM.&hl=pt-BR&v=zmiYzsHi8INTJBWt2QZC9aM5&size=invisible&cb=sh8hupmkvxlc"


def get_rf():
    recaptcha_response = reCaptchaV3(ANCHOR_URL, timeout=20)
    headers = {**BASE_HEADERS, **{"g-rcp-tkn": recaptcha_response}}
    res = requests.post(url=BASE_URL, json=BASE_PAYLOAD, headers=headers)
    return res.json()


def save_csv(products):
    df = pd.DataFrame(products)
    df.to_csv(f"{LOCAL_PATH}/app-renda-fixa/products/rf.csv", index=False)


def handler():
    products = get_rf()
    save_csv(products)


# handler()
x = pd.read_csv(f"{LOCAL_PATH}/app-renda-fixa/products/rf.csv")
n = 0