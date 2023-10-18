import requests
import time
import pymongo

class Samu():

    def __init__(self, ocorrencia, carro, notificar):
        self.ocorrencia = ocorrencia
        self.carro = carro
        self.notificar = notificar
    # gets pra ir pegando os valores de samu
    def get_ocorrencia(self):
        return self.ocorrencia

    def get_carro(self):
        return self.carro

    def get_notificar(self):
        return self.notificar

    def __str__(self):
        return f'a ocorrencia {self.ocorrencia} sera atendidida pelo carro {self.carro} e {self.notificar}'
    # fiz esse str pra poder ir printando e testando

while True:
    ocorrencia = input("Digite a ocorrencia: ")
    placa = input("Digite a placa do veiculo: ")
    notificar = input("Digite a notificação: ")
    #inputs pro usuário ir colocando as infos
    samu = Samu(ocorrencia, placa, notificar)
    # print(samu)

    """database.mensagensSamu.insert_one({
        "ocorrencia": samu.get_ocorrencia(),
        "placa": samu.get_carro(),
        "notificacao": samu.get_notificar()})"""

    # inserindo no banco de dados

    data = {'samu': {samu.get_ocorrencia(),
                  samu.get_carro(),
                samu.get_notificar()}}
    # montando o dicionario pra enviar via post
    r = requests.post("http://127.0.0.1:5000/", data)
    # And done.
    print(data)
    print(r.text)  # displays the result body.
    time.sleep(5)
