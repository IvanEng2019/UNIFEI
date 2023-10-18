from bson.objectid import ObjectId
from flask import Flask, request
from flask_pymongo import PyMongo
from bson.json_util import dumps
from flask_cors import CORS

app = Flask(__name__)
CORS(app)
app.config["MONGO_URI"] = "mongodb://localhost:27017/Frinhani"
mongo = PyMongo(app)
database = mongo.db


@app.route('/')
def index():
    return dumps({"mensagem": "Endpoint Cemig"})

#retorna todas as ocorrencias em aberto
@app.route("/ocorrencias", methods = ['GET'])
def ocorrencias():
    ocorrencias = database.ocorrenciasCemig.find( {"situacao" : 'Em andamento'})
    ocorrencias = list(ocorrencias)
    return dumps(ocorrencias)

#retorna todas as ocorrencias
@app.route("/ocorrencias/all", methods = ['GET'])
def allOcorrencias():
    ocorrencias = database.ocorrenciasCemig.find({})
    ocorrencias = list(ocorrencias)
    return dumps(ocorrencias)

#salva uma ocorrencia no banco
@app.route("/ocorrencia", methods=['POST'])
def addOcorrencia():
    
    data = request.get_json(force=True)
    print("Recebeu ocorrencia de: " + data['autor'])
    print("Descrição: " + data['descricao'])
    print("Endereço: " + data['endereco'])
    print("Regiao: "+data['regiao'])
    print("Tipo: "+ data['tipo'])
    
    #manda uma confirmacao de volta deq recebeu oq foi enviado
    database.ocorrenciasCemig.insert_one({
        "descricao" : data['descricao'],
        "autor" : data['autor'],
        "tipo" :data['tipo'],
        "endereco" : data['endereco'],
        "regiao" : data['regiao'],
        "situacao" : "Em andamento"})    
    return dumps({"Mensagem" : "Registrado"})


#Atualiza a situacao de uma ocorrencia
@app.route("/ocorrencias/atualizar",methods=["POST"])
def atualizarOcorrencia():
    data = request.get_json(force=True)
    _id = data['_id']
    situacao = data['situacao']
    oid = ObjectId(_id)
    database.ocorrenciasCemig.update_one({"_id" :oid },{ "$set" : {"situacao" : situacao}})
    return dumps({"mensagem" : "situacao atualizada"})

#registra uma nova mensagem
@app.route("/mensagem/<origem>", methods=["POST"])
def inserirMensagem(origem):
    data = request.get_json(force=True)
    conteudo = data['conteudo']
    tipo = data['tipo']
    print("Recebeu mensagem de "+origem)
    print("Conteudo: "+conteudo)
    print("Tipo: "+tipo)
    
    #salva no banco e confirma que recebeu
    database.mensagensCemig.insert_one({
        "conteudo" : conteudo,
        "tipo" : tipo,
        "origem" : origem,
        "lida" : False})
    return dumps({"mensagem": "mensagem recebida"})

#atualiza o status de uma mensagem
@app.route("/mensagens/atualizar",methods=["POST"])
def atualizarMensagem():
    data = request.get_json(force=True)
    _id = data['_id']
    o_id = ObjectId(_id)
    lida = data['lida']
    database.mensagensCemig.update_one({"_id" : o_id}, {"$set" : {"lida" : lida}})
    return dumps({"mensagem" : "mensagem Atualizada"})

#mostra todas as mensagens
@app.route("/mensagens/all",methods=["GET"])
def getAllMensagens():
    mensagens = database.mensagensCemig.find()
    return dumps(mensagens)

#mostra as mensagens nao lidas
@app.route("/mensagens",methods=["GET"])
def getMensagens():
    mensagens = database.mensagensCemig.find({"lida" : False})
    mensagens = list(mensagens)
    return dumps(mensagens)

app.run(port = 3001,debug=True)