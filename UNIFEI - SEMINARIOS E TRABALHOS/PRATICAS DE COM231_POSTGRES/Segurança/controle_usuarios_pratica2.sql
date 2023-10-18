----------
--Comandos para verificar as roles e seus privilégios no banco

SELECT * FROM pg_roles where rolname = 'programadores';
select * from information_schema.role_table_grants where grantee='user1';

--------------------------------------------------------
--PRÁTICA 2

--QUESTÃO 1
--a)
CREATE ROLE dba_northwind;
GRANT ALL PRIVILEGES ON DATABASE "Northwind" TO dba_northwind;
GRANT ALL ON ALL TABLES IN SCHEMA northwind TO dba_northwind;
GRANT USAGE ON SCHEMA northwind TO dba_northwind;


--b)
CREATE USER dba WITH PASSWORD '12345';
GRANT dba_northwind TO dba;

--c)
select * from northwind.categories;
ALTER TABLE northwind.categories ADD COLUMN teste int default 0;

--d)
ALTER TABLE northwind.categories OWNER TO postgres;  
ALTER TABLE northwind.categories ADD COLUMN teste int default 0;
SELECT * FROM northwind.categories;

e)
REVOKE DELETE ON TABLE northwind.orders FROM programadores;
REVOKE DELETE ON TABLE northwind.categories FROM programadores;

f)
select * from information_schema.role_table_grants where grantee='programadores';
select tablename, tableowner From pg_tables 



/*O banco de dados PostgreSQL é do tipo ‘objeto-relacional’. Isso significa que
ele implementa conceitos da orientação objeto em seu modelo. Dessa forma, tabelas,
roles, usuários, são objetos no banco e possuem ‘um dono’. Ou seja, quem criou aquele
‘objeto’ tem direitos sobre ele. No caso dos comandos SQL GRANT e REVOKE, isso tem
diversas implicações. Vamos testá-las nessa atividade. Crie uma role, cujo perfil é de
‘DBA de Banco de Dados’. Ou seja, terá todos os privilégios sobre o banco Northwind.*/
CREATE ROLE dba_northwind;
GRANT ALL PRIVILEGES ON DATABASE northwind TO dba_northwind;/* concede todos os privilegios sobre o banco*/
GRANT ALL ON ALL TABLES IN SCHEMA northwind TO dba_northwind;/* concede todos os privilegios sobre as tabelas*/
GRANT USAGE ON SCHEMA northwind TO dba_northwind; /*"superusuário"*/

/*Crie um usuário e associe ele a esse perfil.*/
CREATE USER dba WITH PASSWORD '123';
GRANT dba_northwind TO dba;

/*Faça login no banco com o perfil criado e execute a seguinte operação no banco:
inserir uma coluna na tabela ‘categories’.*/
select * from northwind.categories;
ALTER TABLE northwind.categories ADD COLUMN teste int default 0;

/*Qual o resultado da operação executada?
deve ser o proprietário das categorias da tabela*/
ALTER TABLE northwind.categories OWNER TO postgres;  
ALTER TABLE northwind.categories ADD COLUMN teste int default 0;
SELECT * FROM northwind.categories;

/*Ainda logado como o usuário  DBA, remova da role
‘programadores’ o privilégio de realizar ‘delete’ na tabela ‘Orders.*/
REVOKE DELETE ON TABLE northwind.orders FROM programadores;
REVOKE DELETE ON TABLE northwind.categories FROM programadores;

/*Qual o resultado da operação executada */
select * from information_schema.role_table_grants where grantee='programadores';
select tablename, tableowner From pg_tables 






--QUESTÃO 2
--a)
CREATE USER user1 WITH PASSWORD '12345';
GRANT INSERT, SELECT, UPDATE, DELETE ON TABLE northwind.categories, northwind.customers, northwind.products TO user1 WITH GRANT OPTION;
GRANT USAGE ON SCHEMA northwind TO user1;

--b)
CREATE USER user2 WITH PASSWORD '12345';
GRANT INSERT, SELECT, UPDATE, DELETE ON TABLE northwind.categories, northwind.orders, northwind.order_details TO user2 WITH GRANT OPTION;
GRANT USAGE ON SCHEMA northwind TO user2;

--c)
CREATE USER user3 WITH PASSWORD '12345';
GRANT SELECT ON ALL TABLES IN SCHEMA northwind TO user3;
GRANT USAGE ON SCHEMA northwind TO user3;
select * from information_schema.role_table_grants where grantee='user3' ORDER BY grantor;

--d)
GRANT INSERT, SELECT, UPDATE, DELETE ON TABLE northwind.categories, northwind.customers, northwind.products TO user3 WITH GRANT OPTION;

--e)
GRANT INSERT, SELECT, UPDATE, DELETE ON TABLE northwind.categories, northwind.orders, northwind.order_details TO user3 WITH GRANT OPTION;

--g)
REVOKE ALL PRIVILEGES ON ALL TABLES IN SCHEMA northwind FROM user3;
REVOKE ALL PRIVILEGES ON schema northwind FROM user3; 
DROP ROLE user3;

REVOKE ALL PRIVILEGES ON ALL TABLES IN SCHEMA northwind FROM user1 CASCADE;
REVOKE ALL PRIVILEGES ON schema northwind FROM user1 CASCADE; 
REVOKE ALL PRIVILEGES ON ALL TABLES IN SCHEMA northwind FROM user2 CASCADE;
REVOKE ALL PRIVILEGES ON schema northwind FROM user2 CASCADE; 
