CREATE TABLE Personagem (
    id_personagem integer  PRIMARY KEY,
    nome varchar (100) NOT NULL unique,
    origem varchar (20) NOT NULL,
    genero varchar(6) NOT NULL CHECK (genero IN ('Male', 'Female', 'Other')),
    data_comic date NOT NULL,
    aniversario date,
    descricao text NOT NULL,
    num_edicoes_aparece integer NOT NULL
);

CREATE TABLE Filme (
    id_filme integer  PRIMARY KEY,
    nome varchar (200) NOT NULL unique,
    descricao text NOT NULL,
    data_lacamento date NOT NULL,
    data_comic date NOT NULL,
    tempo varchar(15) NOT NULL,
    classificacao varchar(30) NOT NULL,
    orcamento Real NOT NULL CHECK (orcamento > 0),
    receita_bilheteria Real NOT NULL CHECK (receita_bilheteria > 0)
);

CREATE TABLE SuperPoder (
    id_poder integer PRIMARY KEY,
    nome varchar(30) NOT NULL unique,
    descricao text NOT NULL,
    data_comic date NOT NULL 
);

CREATE TABLE volume (
    id_volume integer PRIMARY KEY,
    nome varchar(15) NOT NULL unique,
    num_edicoes integer NOT NULL,
    data_comic date NOT NULL,
    descricao text NOT NULL,
    ultima_edicao varchar(200) NOT NULL DEFAULT 'Sem Última Edição.',
    primeira_edicao varchar (200) NOT NULL 
);

CREATE TABLE Editor (
    id_editor integer  PRIMARY KEY,
    nome_editor varchar (100) NOT NULL unique,
    descricao text NOT NULL,
    data_comic date NOT NULL,
    estado varchar(50) NOT NULL DEFAULT 'Dado não informado.',
    cidade varchar(100) NOT NULL DEFAULT 'Dado não informado.',
    rua varchar(200) NOT NULL DEFAULT 'Dado não informado.'
);

CREATE TABLE producao (
    fk_Personagem_id_personagem integer ,
    fk_Filme_id_filme integer,
	FOREIGN KEY (fk_Personagem_id_personagem) REFERENCES Personagem (id_personagem),
	FOREIGN KEY (fk_Filme_id_filme) REFERENCES Filme (id_filme)
);

CREATE TABLE heroi (
    fk_Personagem_id_personagem integer ,
    fk_SuperPoder_id_poder integer,
	FOREIGN KEY (fk_Personagem_id_personagem) REFERENCES Personagem (id_personagem),
	FOREIGN KEY (fk_SuperPoder_id_poder) REFERENCES SuperPoder (id_poder)
);
    