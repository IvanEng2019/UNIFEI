CREATE DATABASE indexacao

create schema i

CREATE TABLE i.departamento(
	numeroDepto int,
	nomeDepto varchar(30) not null,
	primary key(numeroDepto)
)
INSERT INTO i.departamento VALUES (1, 'Recursos Humanos');
INSERT INTO i.departamento VALUES (2, 'Producao');
INSERT INTO i.departamento VALUES (3, 'Financeiro');
INSERT INTO i.departamento VALUES (4, 'Almoxarifado');

CREATE TYPE sexo_t AS ENUM ('M', 'F');

CREATE TABLE i.funcionario(
	numeroRegistro SERIAL UNIQUE NOT NULL,
	nomeFunc varchar(30) not null,
	sexo sexo_t not null,
	dataNasc date not null,
	depto int not null,	
	primary key(numeroRegistro)
)

--inserir 1000000 registros com valores aleatórios na tabela funcionario
insert into i.funcionario (
    nomeFunc, sexo, dataNasc, depto
)
select
    substr(md5(random()::varchar(30)), 0, 30),
	(enum_range(NULL::sexo_t))[floor(random() * (2-1 + 1) + 1)],
    date(timestamp '1990-01-01' + random() * (timestamp '1990-12-31' - timestamp '2000-01-01')),
    floor(random()* (4-1 + 1) + 1)	
from generate_series(1, 1000000) s(i)

SELECT * FROM i.funcionario;
SELECT * FROM i.departamento;

create role leitura;
create role lgae;
create role viewtotaldep;

REVOKE ALL PRIVILEGES ON ALL TABLES IN SCHEMA i FROM a3 CASCADE;
REVOKE ALL PRIVILEGES ON schema i FROM a3 CASCADE;
REVOKE ALL PRIVILEGES ON dadosA3 FROM a3 CASCADE;
DROP ROLE a3;/*user 3 excluido*/

CREATE USER a1 WITH PASSWORD '123';
CREATE USER a2 WITH PASSWORD '123';
CREATE USER a3 WITH PASSWORD '123';

select * from i.departamento
select * from i.funcionario

GRANT leitura TO a1
GRANT lgae TO a2;
GRANT viewtotaldep TO a3

SELECT * FROM pg_roles where rolname = 'a1';
SELECT * FROM information_schema.role_table_grants where grantee='a1';
SELECT * FROM pg_roles where rolname = 'a2';
SELECT * FROM information_schema.role_table_grants where grantee='a2';
SELECT * FROM pg_roles where rolname = 'a3';
SELECT * FROM information_schema.role_table_grants where grantee='a3';

CREATE VIEW dadosA3 AS
	 (SELECT depto, count(depto) as total_empregado
	  FROM i.funcionario
      GROUP BY depto);
/*Conceda o privilégio de leitura sobre a View para a role ‘A3’*/
GRANT SELECT ON dadosA3 TO viewtotaldep;
GRANT USAGE ON SCHEMA i TO viewtotaldep;

select * from dadosA3;
GRANT SELECT ON i.funcionario TO leitura;
GRANT USAGE ON SCHEMA i TO leitura;
GRANT SELECT,INSERT,UPDATE,DELETE ON i.funcionario TO lgae WITH GRANT OPTION;




















