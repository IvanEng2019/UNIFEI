const mongoose = require('mongoose');


const mensagemSchema = new mongoose.Schema({
   conteudo : {
        type : String,
        required : true
   },
   
   origem : {
    type : String
   },
   
   tipo : {
        type : String,
        required : true
   },

   lida : {
       type : Boolean,
       required : true
   }
});

const Mensagem = mongoose.model('mensagemPolicia', mensagemSchema,"mensagensPolicia");
module.exports = Mensagem;