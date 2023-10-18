/*Seguindo as boas práticas de segurança, você deve criar perfis de usuário
no banco e posteriormente adicionar usuários a esses perfis.
a) Crie uma role chamada ‘programadores’, com o privilégio de CRUD em todas as
tabelas do banco. b) Crie uma role chamada ‘gerente’. Daremos privilégios para essa role nas
próximas questões*/
CREATE ROLE programadores;
GRANT INSERT, SELECT, UPDATE, DELETE ON ALL TABLES IN SCHEMA northwind TO programadores;
CREATE ROLE gerente;

/*Criação de usuário no banco de dados. Crie um usuário com seu nome no banco de dados Northwind
Faça login com esse novo usuário e  Verifique os privilégios do usuário*/
CREATE USER ivan WITH PASSWORD '12345';
SELECT * FROM northwind.categories;/*ivan não tem acesso ao schema ainda, apenas login*/

/*Concedendo privilégios ao usuário. 
Considere que o usuário que você criou na questão 3 é um usuário do tipo
‘programador’. Insira ele na role criada na questão 2. Verifique o que é possível realizar no banco e
Simule falhas associadas a falta de privilégios por esse usuário*/

GRANT programadores TO ivan; /*ivan é atrelado a role/grupo programadores, tendo os direitos atribuidos 
por meio de programadores: crud sobre os registros das tabelas*/
GRANT USAGE ON SCHEMA northwind TO programadores; /*ivan terá como usar o schema atraves de programdores */

SELECT * FROM northwind.categories; /* permitido */
INSERT INTO northwind.categories(categoryid, categoryname, description) VALUES (200, 'teste', 'testando privilegios');/* permitido */
UPDATE northwind.categories SET categoryname = 'teste 200' WHERE categoryid = 200; /* permitido */
DELETE FROM northwind.categories WHERE categoryid = 200;/* permitido */
CREATE TABLE northwind.teste (a int primary key); /* ivan nao tem direito de criar tabela */
DROP TABLE northwind.teste; /* ivan nao tem direito de deletar a tabela */

/*Removendo privilégios do usuário.Remova da role ‘programadores’ o privilégio de realizar ‘delete’ 
na tabela ‘Categories’. Teste a remoção do privilégio*/
REVOKE DELETE ON TABLE northwind.categories FROM programadores;/*ivan não terá mais direito de deletar registros da tabela categoria*/
DELETE FROM northwind.categories WHERE categoryid = 200;/* não permitido - sem direito de excluir registros da tabela*/

/* Exclusão da role*/
DROP ROLE programadores; /* Como existe privelegios atrelados a ivan, não será possivel excluir.
devera ser retirados todos direitos atribuidos pela role. */
REVOKE ALL PRIVILEGES ON schema northwind FROM programadores;/* remove direito de uso sobre o schema para programadores*/
REVOKE ALL PRIVILEGES ON ALL TABLES IN schema northwind FROM programadores; /* remove todos os direitos de todas as tabelas */
DROP ROLE programadores;/* Apos a remoção de todos os direitos é excluida a role*/

/*É possível conceder privilégios sobre Views. A associação dos comandos GRANT e VIEW permite que
se limite o acesso de registros a usuários (e não apenas a nível de coluna, como no GRANT). 
É possível também permitir que usuários tenham acesso apenas a relatórios. Crie uma view chamada 
‘relatorio’, sobre as tabelas Orders e OrderDetails onde: Total_produtos é o total de produtos 
comprados no pedido e Total_pedido é a soma dos valores de todos os produtos comprados.*/

SELECT * FROM northwind.orders
SELECT * FROM northwind.order_details where orderid = 11038

CREATE VIEW relatorio AS (SELECT o.orderid, o.customerid, o.employeeid, count(od.orderid) as total_produtos, sum(od.unitprice) as total_pedido
FROM northwind.orders o, northwind.order_details od
WHERE o.orderid = od.orderid
GROUP BY (o.orderid));
SELECT * FROM relatorio;

/*Conceda o privilégio de leitura sobre a View para a role ‘gerente’*/
GRANT SELECT ON relatorio TO gerente;

/*Crie o usuário ‘gestor’ e adicione ele na role*/
CREATE USER gestor WITH PASSWORD '123'; /*permite o login pelo gestor*/
GRANT gerente TO gestor; /*coloca o gestor no grupo gerente*/
GRANT USAGE ON SCHEMA northwind TO gerente; /* Permiteao grupo gerente o uso do banco*/
SELECT * FROM northwind.orders; /* sem direito de leitura dos registros da tabela*/
SELECT * FROM northwind.order_details;  /* sem direito de leitura dos registros da tabela*/
SELECT * FROM relatorio; /*leitura realizadacom sucesso*/

/* Comandos para verificar as roles e seus privilégios no banco*/
SELECT * FROM pg_roles where rolname = 'gerente';
SELECT * FROM information_schema.role_table_grants where grantee='gerente';

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
ALTER TABLE northwind.categories ADD COLUMN teste int default 0;/*erro*/
/*Qual o resultado da operação executada? erro, deve ser o proprietário das categorias da tabela*/
ALTER TABLE northwind.categories OWNER TO dba;  /*dba passa a ter direito de proprietário da tabela*/
ALTER TABLE northwind.categories ADD COLUMN teste int default 0; /*adiciona tabela*/
SELECT * FROM northwind.categories;

/*Ainda como o usuário DBA, remova da role ‘programadores’ o privilégio de realizar ‘delete’ na tabela ‘Orders.*/
REVOKE DELETE ON TABLE northwind.orders FROM programadores;/*não consegue remover privilegio 
da tabela orders apenas de categories*/
REVOKE DELETE ON TABLE northwind.categories FROM programadores;/*realizado*/

select * from information_schema.role_table_grants where grantee='programadores';
/* mostra profrmador com todos direito exceto sem direito de delete*/
select tablename, tableowner From pg_tables /*mostra dba como proprietario decategories*/ 

/* Testando o ‘WITH GRANT OPTION’.
a) Crie um novo usuario no banco chamado ‘user1’ e dê a ele privilégios de CRUD
nas tabelas categories, customers e products. Utilize o ‘with grant option’.
Lembrem-se que essa não é uma boa prática de segurança!*/
CREATE USER user1 WITH PASSWORD '12345';
GRANT INSERT, SELECT, UPDATE, DELETE ON TABLE northwind.categories, northwind.customers, northwind.products TO user1 WITH GRANT OPTION;
GRANT USAGE ON SCHEMA northwind TO user1;

/*b) Crie um novo usuario no banco chamado ‘user2’ e dê a ele privilégios de CRUD
nas tabelas orders e orderdetails. Utilize o ‘with grant option’.*/
CREATE USER user2 WITH PASSWORD '12345';
GRANT INSERT, SELECT, UPDATE, DELETE ON TABLE northwind.categories, northwind.orders, northwind.order_details TO user2 WITH GRANT OPTION;
GRANT USAGE ON SCHEMA northwind TO user2;

/*c) Crie um novo usuario no banco chamado ‘user3’ e dê a ele privilégios de SELECT
em todas as tabelas do schema northwind.*/
CREATE USER user3 WITH PASSWORD '12345';
GRANT SELECT ON ALL TABLES IN SCHEMA northwind TO user3;
GRANT USAGE ON SCHEMA northwind TO user3;
select * from information_schema.role_table_grants where grantee='user3' ORDER BY grantor;

/*d) Agora, o user1 vai repassar os privilégios dele para o user3.*/
GRANT INSERT, SELECT, UPDATE, DELETE ON TABLE northwind.categories, northwind.customers, northwind.products TO user3 WITH GRANT OPTION;

/*e) De forma análoga, o user2 repassará os privilégios dele para o user3.*/
GRANT INSERT, SELECT, UPDATE, DELETE ON TABLE northwind.categories, northwind.orders, northwind.order_details TO user3 WITH GRANT OPTION;

/*f) Qual o efeito das operações executadas nas letras d e e no banco?
user 3 passa a ter mais direitos do que o de leitura concedidos inicialmente.*/

/*g) Logado como postgres, remova os privilégios no user3. O que acontece? Como resolver*/
REVOKE ALL PRIVILEGES ON ALL TABLES IN SCHEMA northwind FROM user3; 
REVOKE ALL PRIVILEGES ON schema northwind FROM user3; 
/* remove todos os privilegios acima concedidos pelo usuario postgres*/
DROP ROLE user3; /* não consegue excluir usuario 3, pois o mesmo apresenta
direios concedidos pelos usuarios 1 e 2 */

/*A única forma é excluido todos os provilegios concedidos a todos os usuarios que concederam ao user 3 de forma cascata*/
REVOKE ALL PRIVILEGES ON ALL TABLES IN SCHEMA northwind FROM user1 CASCADE;
REVOKE ALL PRIVILEGES ON schema northwind FROM user1 CASCADE; 
REVOKE ALL PRIVILEGES ON ALL TABLES IN SCHEMA northwind FROM user2 CASCADE;
REVOKE ALL PRIVILEGES ON schema northwind FROM user2 CASCADE; 
DROP ROLE user3;/*user 3 excluido*/


