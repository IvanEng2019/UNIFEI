const express = require('express');
const mongoose = require('mongoose');
const cors = require('cors');

const app = express();
const bodyParser = require('body-parser');

const routes = require('./routes');

app.use(cors());
app.use(bodyParser.json());
app.use(express.Router());

//escuta na porta 3000, e qnd tiver pronto pra começar a escutar printa no console pra vc ter noção
const dbURI = "mongodb://localhost:27017/Frinhani";
mongoose.connect(dbURI, { useNewUrlParser: true, useUnifiedTopology: true, useCreateIndex:true })
  .then((result) => {app.listen(3002); console.log("conectado no 3002")})
  .catch((err) => console.log(err));

app.use(routes);