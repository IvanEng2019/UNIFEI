--QUESTÃO 1A
CREATE DATABASE indexacao;
show data_directory;

--QUESTÃO 1B
CREATE TABLE departamento(
	numeroDepto int,
	nomeDepto varchar(30) not null,
	primary key(numeroDepto)
)

--QUESTÃO 1C
INSERT INTO departamento VALUES (1, 'Recursos Humanos');
INSERT INTO departamento VALUES (2, 'Producao');
INSERT INTO departamento VALUES (3, 'Financeiro');
INSERT INTO departamento VALUES (4, 'Almoxarifado');

--QUESTÃO 2A
SELECT * FROM departamento;

--QUESTÃO 2B
SELECT ctid, numerodepto, nomedepto FROM departamento;

--QUESTÃO 2C
SELECT ctid, * FROM northwind.order_details;

--QUESTÃO 2D
DELETE FROM departamento;

--QUESTÃO 2E
INSERT INTO departamento VALUES (2, 'Producao');
INSERT INTO departamento VALUES (1, 'Recursos Humanos');
INSERT INTO departamento VALUES (4, 'Almoxarifado');
INSERT INTO departamento VALUES (3, 'Financeiro');

--QUESTÃO 2F
SELECT * FROM departamento;
SELECT ctid, numerodepto, nomedepto FROM departamento;

--QUESTÃO 3A
SELECT * FROM pg_indexes WHERE tablename = 'departamento';

--QUESTÃO 4A
CREATE TYPE sexo_t AS ENUM ('M', 'F');

CREATE TABLE funcionario(
	numeroRegistro SERIAL UNIQUE NOT NULL,
	nomeFunc varchar(30) not null,
	sexo sexo_t not null,
	dataNasc date not null,
	depto int not null,	
	primary key(numeroRegistro)
)

--inserir 1000000 registros com valores aleatórios na tabela funcionario
insert into funcionario (
    nomeFunc, sexo, dataNasc, depto
)
select
    substr(md5(random()::varchar(30)), 0, 30),
	(enum_range(NULL::sexo_t))[floor(random() * (2-1 + 1) + 1)],
    date(timestamp '1990-01-01' + random() * (timestamp '1990-12-31' - timestamp '2000-01-01')),
    floor(random()* (4-1 + 1) + 1)	
from generate_series(1, 1000000) s(i)

SELECT * FROM funcionario;

--QUESTÃO 4B
--PARA LER : https://www.postgresql.org/docs/8.4/storage-fsm.html
SELECT ctid, * FROM funcionario where numeroregistro = 1000000;
SELECT * FROM pg_indexes WHERE tablename = 'funcionario';

--QUESTÃO 5
EXPLAIN ANALYSE SELECT * FROM funcionario WHERE numeroregistro >10000;

EXPLAIN SELECT * FROM funcionario;

--QUESTÃO 6A

EXPLAIN ANALYSE SELECT * FROM funcionario WHERE depto = 2;

--QUESTÃO 6B
CREATE INDEX func_depto ON funcionario USING btree (depto);

--QUESTÃO 6C
EXPLAIN ANALYSE SELECT * FROM funcionario WHERE depto = 2;

--QUESTÃO 7A
EXPLAIN ANALYSE SELECT * FROM funcionario WHERE sexo = 'M' AND depto = 3

--QUESTÃO 7B
DROP INDEX func_depto;

--QUESTÃO 7C
EXPLAIN ANALYSE SELECT * FROM funcionario WHERE sexo = 'M' AND depto = 3

--QUESTÃO 7D
CREATE INDEX func_sexo_depto ON funcionario USING btree (depto, sexo);

--QUESTÃO 7E
EXPLAIN ANALYSE SELECT * FROM funcionario WHERE sexo = 'M' AND depto = 3

--QUESTÃO 8A
CREATE INDEX func_parcial_nascimento ON funcionario USING btree (dataNasc)
	WHERE EXTRACT(YEAR FROM dataNasc) = 1987

EXPLAIN ANALYSE SELECT * FROM funcionario WHERE EXTRACT(YEAR FROM dataNasc) = 1987; 

--QUESTÃO 8B
CREATE INDEX func_parcial_nome ON funcionario (left(nomeFunc, 1));

EXPLAIN ANALYSE SELECT nomeFunc FROM funcionario WHERE nomeFunc = 'a%'
