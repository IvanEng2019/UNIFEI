const express = require ('express');
const bodyParser=require('body-parser');
const mysql=require('mysql');
const handlebars=require ('express-handlebars');
const app=express();
const urlencodeParser=bodyParser.urlencoded({extended:false});
const sql=mysql.createConnection({
    host:'localhost',
    user:'root',
    password:'',
    port:3306
});

sql.query("use redes");

app.engine("handlebars",handlebars({defaultLayout:'main'}));
app.set("view engine","handlebars");

app.use("/css",express.static('css'));
app.use("/js",express.static('js'));
app.use("/img",express.static('img'));

//tela de abertura
app.get("/",function(req,res){
    res.render(__dirname+'/views/layouts/index');
});

//Cludes do colaborador
//Inserir colaborador
app.get("/inserir_funcionario",function(req,res){
   res.render(__dirname+'/views/layouts/inserir_funcionario');
});

app.post("/inserir_funcionario",urlencodeParser,function(req,res){
    sql.query("insert into funcionario values(?,?,?,?,?,?,?,?)",[,req.body.nome,req.body.cpf,req.body.genero,req.body.data,req.body.endereco,req.body.telefone,req.body.email]);
    console.log("Funcionário " + req.body.nome + " Adicionado!");
    res.render(__dirname+'/views/layouts/inserir_funcionario');
});

//listar colaborador
app.get("/listar_funcionario",function(req,res){    
    sql.query("select * from funcionario order by id asc", function(err,results,fields){
        if(results!= ''){
            res.render(__dirname+'/views/layouts/listar_funcionario',{tabFun:results});
        }
        else{
            console.log("Não existe Colaborador cadastrado!");
            res.render(__dirname+'/views/layouts/index');
        }
    });
 });

 //excluir colaborador
app.get("/deletar_funcionario/:id",function(req,res){
    sql.query('delete from funcionario where id=?',[req.params.id]);
    console.log("Funcionário " + req.params.name + " excluido!");
    res.render(__dirname+'/views/layouts/listar_funcionario');
    //res.render(__dirname+'/views/layouts/index');
});

//atualizar colaborador
app.get('/atualizar_funcionario/:id',function(req,res){
    sql.query('select * from funcionario where id=?',[req.params.id],function(err,results,fields){
        res.render(__dirname+'/views/layouts/atualizar_funcionario',{id:req.params.id, nome:results[0].nome, cpf:results[0].cpf, genero:results[0].genero, nasc:results.nasc, endereco:results[0].endereco, telefone:results[0].telefone, email:results[0].email});
    });
});
app.post('/atualizar_funcionario',urlencodeParser,function(req,res){
    sql.query("update funcionario set nome=? ,cpf=? ,genero=? ,nasc=? ,endereco=? ,telefone=? ,email=? where id=?",[req.body.nome, req.body.cpf, req.body.genero, req.body.nasc, req.body.endereco, req.body.telefone, req.body.email, req.body.id]);
    console.log("Funcionário " + req.body.nome + " atualizado!");
    res.render(__dirname+'/views/layouts/index');
});

 //cludes da EPI
 //Inserir Epi
app.get("/inserir_epi",function(req,res){
    sql.query("select id from funcionario", function(err,results,fields){
        console.log(results);
        if( results == ''){
            console.log("Insira primeiro ao menos um Funcionário");
            res.render(__dirname+'/views/layouts/index');
        }
        else{
            var idFun = [];
            //console.log('The solution is: ', rows.length);
            for (var i =0; i < results.length; i++) {
                //console.log('The solution is: ', rows[i]["id"]);
                idFun.push(results[i]["id"]);
            }
            console.log(idFun);
            res.render(__dirname+'/views/layouts/inserir_epi', {idFun : idFun});           
        }
    });
 });

app.post("/inserir_epi",urlencodeParser,function(req,res){   
    sql.query("insert into epis values(?,?,?,?,?,?,?,?,?)",[, req.body.idFuncionario, 
        req.body.nome, req.body.fornecedor, req.body.especificacao, req.body.uso, req.body.certificado,
        req.body.modelo, req.body.rfdi],function(err,results,fields){
            console.log(results);
            if(!err){ 
                console.log("Epi " + req.body.nome + " inserida!");
                res.render(__dirname+'/views/layouts/inserir_epi');
            }
            else{
                console.log("Insira o id do Funcionário existente");
                res.render(__dirname+'/views/layouts/inserir_epi');
            }
        });
});

//Listar Epis
app.get("/listar_epi",function(req,res){    
    sql.query("select * from epis order by id asc", function(err,results,fields){
        if(results != ''){
            res.render(__dirname+'/views/layouts/listar_epi',{tabEpi:results});
        }
        else{
            console.log("Não existe EPI cadastrado!");
            res.render(__dirname+'/views/layouts/index');
        }
    });
 });

//excluir epi
app.get("/deletar_epi/:id",function(req,res){
    sql.query('delete from epis where id=?',[req.params.id]);
    console.log("Epi " + req.params.name +  " excluida!");
    //res.render(__dirname+'/views/layouts/index');
    res.render(__dirname+'/views/layouts/listar_epi');
});

//atualizar Epi
app.get("/atualizar_epi/:id",function(req,res){
    sql.query('select * from epis where id=?',[req.params.id],function(err,results,fields){
        res.render(__dirname+'/views/layouts/atualizar_epi',{id:req.params.id, func_id:results.func_id, 
            nome:results[0].nome, fornecedor:results[0].fornecedor, especificacao:results[0].especificacao,
             uso:results[0].uso, certificado:results[0].certificado, modelo:results[0].modelo, tag:results[0].tag});
    });
});
app.post("/atualizar_epi",urlencodeParser,function(req,res){
    sql.query("update epis set nome=? ,fornecedor=? ,especificacao=? ,uso=? ,certificado=? ,modelo=? ,tag=? where id=?",
    [req.body.nome, req.body.fornecedor, req.body.especificacao, req.body.uso, req.body.certificado, req.body.modelo,
     req.body.tag, req.body.id]);
    console.log("Epi " + req.body.nome + " atualizada!");
    res.render(__dirname+'/views/layouts/index');
});


 //Inserir registro de uso RFDI
 app.get("/externo",function(req,res){
     sql.query("select * from epis", function(err,results,fields){
       // console.log(results);
        if(results == '' ){
            console.log("Insira primeiro ao menos um EPI");
            res.render(__dirname+'/views/layouts/index');
        }
        else{
            var idEpi = [];
            //console.log('The solution is: ', rows.length);
            for (var i =0; i < results.length; i++) {
                //console.log('The solution is: ', rows[i]["id"]);
                idEpi.push(results[i]["id"]);
            }
            console.log(idEpi);
            res.render(__dirname+'/views/layouts/externo', {idEpi : idEpi});          
        }
    });
 });

 //tela de controle
app.get("/controle",function(req,res){
    sql.query("select r.id, r.event, r.time, r.epi_id, e.tag, e.func_id, f.nome from epis as e, funcionario as f, registro as r where f.id=e.func_id and e.id=r.epi_id",
                function(err,results,fields){
                    if(results == ''){
                        console.log(" EPIS e funcionarios nao encontradoS!");
                        res.render(__dirname+'/views/layouts/index');
                    }
                    else{
                        console.log("teste");
                        console.log(results[0].time);
                        //console.log(results[1].event);
                        for (var i=0; i<results.length; i++){
                            if (results[i].event == 1){
                                results[i].event = 'Entrada';
                            } else{
                                results[i].event = 'Saída';
                            }
                        }
                        res.render(__dirname+'/views/layouts/controle',{tabReg:results});  
                    }
                });         
});

app.post("/controle",urlencodeParser,function(req,res){   
    sql.query("insert into registro values(?,?,?,?)",[,req.body.epi_id, req.body.evento, req.body.tempo],
    function(err,results,fields){
            if(!err){ 
                console.log("Registro inserido!");
                sql.query("select r.id, r.event, r.time, r.epi_id, e.tag, e.func_id, f.nome from epis as e, funcionario as f, registro as r where f.id=e.func_id and e.id=r.epi_id",
                function(err,results,fields){
                    if(results == ''){
                        console.log(" EPIS e funcionarios nao encontradoS!");
                        res.render(__dirname+'/views/layouts/index');
                    }
                    else{
                        console.log("testando");
                        console.log(results[0].event);
                        console.log('results[0].event');
                        /* if (results[0].event == 1){
                            results[0].event = 'Entrada';
                        } else{
                            results[0].event = 'Saída';
                        } */
                        
                        res.render(__dirname+'/views/layouts/controle',{tabReg:results});  
                    }
                });                 
            }
            else{
                console.log("Insira o id do EPI existente");
                res.render(__dirname+'/views/layouts/index');
            }
        });
});

app.get("/equipe",function(req,res){
    res.render(__dirname+'/views/layouts/equipe');
 });

app.listen(3000,function(req,res){
    console.log[("servidor rodando")];
});