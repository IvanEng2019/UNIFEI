from flask import Flask, request
from flask_pymongo import PyMongo
from flask_cors import CORS
from bson.json_util import dumps

app = Flask(__name__)
CORS(app)

app.config["MONGO_URI"] = "mongodb://localhost:27017/Frinhani"
mongo = PyMongo(app)
database = mongo.db

@app.route("/")
def main():
    return "endpoint samu"

@app.route('/ocorrencia', methods=['POST'])
def result():

    #print(request.form.getlist('samu'))
    data = request.get_json(force=True)
    ocorrencia = data['ocorrencia']
    placa = data['placa']
    notificacao = data['notificacao']

    database.ocorrenciasSamu.insert_one({
        "ocorrencia" : ocorrencia,
        "placa" : placa,
        "notificacao" : notificacao,
        "situacao" : "Em andamento"
    })
    return 'Recebido'  # response to your request.

#retorna todas as ocorrencias em aberto
@app.route("/ocorrencias", methods = ['GET'])
def ocorrencias():
    ocorrencias = database.ocorrenciasSamu.find( {"situacao" : 'Em andamento'})
    ocorrencias = list(ocorrencias)
    return dumps(ocorrencias)

#retorna todas as ocorrencias
@app.route("/ocorrencias/all", methods = ['GET'])
def allOcorrencias():
    ocorrencias = database.ocorrenciasSamu.find({})
    ocorrencias = list(ocorrencias)
    return dumps(ocorrencias)


if __name__ == "__main__":
    app.run(debug=True,port=3003)
