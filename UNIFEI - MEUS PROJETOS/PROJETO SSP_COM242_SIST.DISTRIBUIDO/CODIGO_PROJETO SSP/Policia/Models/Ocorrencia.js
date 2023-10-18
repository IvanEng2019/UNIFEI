const mongoose = require('mongoose');


const ocorrenciaSchema = new mongoose.Schema({
   descricao : {
        type : String,
        required : true
   },
   
   autor : {
    type : String
   },
   
   tipo : {
        type : String,
        required : true
   },

   endereco : {
        type : String
   },

   situacao : {
        type : String,
        default : "Em andamento",
        required : true
   },

   regiao : {
          type : String,
          required : true,
   }
});

const Ocorrencia = mongoose.model('ocorrenciaPolicia', ocorrenciaSchema,"ocorrenciasPolicia");
module.exports = Ocorrencia;