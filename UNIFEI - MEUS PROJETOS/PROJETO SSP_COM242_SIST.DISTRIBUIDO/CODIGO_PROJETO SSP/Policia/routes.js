const {Router} = require('express');
const Ocorrencia = require('./Models/Ocorrencia');
const Mensagem = require('./Models/Mensagem');
const router = Router();

router.all("/", (req,res) => {
    res.send({mensagem : "Endpoint Policia"});
});

//retorna todas as ocorrencias em aberto
router.get("/ocorrencias", async (req,res) => {
    let ocorrencias = await Ocorrencia.find( {situacao : 'Em andamento'});
    res.send(ocorrencias);
});

//retorna todas as ocorrencias
router.get("/ocorrencias/all", async (req,res) => {
    let ocorrencias = await Ocorrencia.find({});
    res.send(ocorrencias);
});

//salva uma ocorrencia no banco
router.post("/ocorrencia", async (req,res) => {
    const {descricao, autor, tipo, endereco, regiao} = req.body;
    console.log("Recebeu ocorrencia de: " + descricao);
    console.log("Descrição: " + descricao);
    console.log("Endereço: " + endereco);
    console.log("Regiao: "+regiao);
    console.log("Tipo: "+ tipo);
    
    //manda uma confirmacao de volta deq recebeu oq foi enviado
    await Ocorrencia.create({descricao, autor, tipo, endereco,regiao}).catch((err) => {console.log(err);res.send("Erro, envie novamente");})
    .then(res.send( {mensagem : "Ocorrencia Recebida"}));
    
});

//pra atualizar o status de uma ocorrencia
router.post("/ocorrencias/atualizar/", async (req,res) => {
    const {_id, situacao} = req.body;
    await Ocorrencia.findByIdAndUpdate(_id,{situacao : situacao});
    res.send("Situacao atualizada");
});

//recebe uma mensagem de uma origem(outra instuicao eg bombeiros,cemig,prefeitura)
router.post("/mensagem/:origem" , async (req,res) => {
    const {conteudo, tipo} = req.body;
    const origem = req.params.origem;
    console.log("Recebeu mensagem de: " + origem);
    console.log("Conteudo: " + conteudo);
    console.log("Tipo: "+ tipo);
    
    //manda uma confirmacao de volta deq recebeu oq foi enviado
    await Mensagem.create({origem,conteudo,tipo,lida: false}).catch((err) => {console.log(err);res.send("Erro, envie novamente");})
    .then(res.send( {mensagem : "Mensagem Recebida"}));
});

//pra atualizar o status de uma mensagem (lido/nao lido)
router.post("/mensagens/atualizar", async (req,res) => {
    const {_id, lida} = req.body;
    await Mensagem.findByIdAndUpdate(_id,{lida: lida});
    res.sendStatus(201);
});

//retorna todas as mensagens
router.get("/mensagens/all", async (req,res) => {
    let mensagens = await Mensagem.find();
    res.send(JSON.stringify(mensagens));
})

//retorna as mensagens nao lidas
router.get("/mensagens" , async (req,res) => {
    let mensagens = await Mensagem.find({lida : false});
    res.send(JSON.stringify(mensagens));
});



module.exports = router;


