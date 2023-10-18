postgres 4 niveis de isolamento:
1-Read uncommitted - leitura não confirmada
1-Read committed - leitura confirmada 
2-Repeatable read - leitura repetivel
3-Serializable  - O mais estrito é Serializable, que é definido pelo padrão em um parágrafo que diz que qualquer execução simultânea de um conjunto de transações Serializable é garantida para produzir o mesmo efeito que executá-las uma de cada vez em alguma ordem. 
o modo Read Uncommitted do PostgreSQL se comporta como Read Committed.

Dirty Read(leitura suja): Uma transação lê dados gravados por uma transação não confirmada
simultânea. - Não faz no postgres 

-- ATIVIDADE 2.2
-- Nonrepeatable read - Leitura não-repetitiva: uma T fará update
Uma transação relê os dados lidos anteriormente e descobre que os dados foram modificados 
por outra transação (aquela confirmada desde a leitura inicial).

--TRANSAÇÃO 2
START TRANSACTION ISOLATION LEVEL READ COMMITTED;
SELECT * FROM northwind.categories WHERE categoryid = 4; -> le maça
--TRANSAÇÃO 1
START TRANSACTION ISOLATION LEVEL READ COMMITTED;
UPDATE northwind.categories SET description = 'banana' WHERE categoryid = 4;
COMMIT
SELECT * FROM northwind.categories WHERE categoryid = 4;
--TRANSAÇÃO 2
SELECT * FROM northwind.categories WHERE categoryid = 4; -> le banana antes de finalizar a T
COMMIT

-> Read uncommitted = Read committed  no PG
-> se fizer ambas T com Serializable - a T sempre le maça
START TRANSACTION ISOLATION LEVEL Serializable -> não ocorre Nonrepeatable read - Leitura não-repetitiva
-> se fizer ambas T com Repeatable read - a T sempre le maça 
START TRANSACTION ISOLATION LEVEL Repeatable read -> não ocorre Nonrepeatable read - Leitura não-repetitiva


-- ATIVIDADE 2.3
--Phanton Read -  Leitura Fantasma: uma T fará insert/delet
Uma transação executa novamente uma consulta retornando um conjunto de linhas que 
satisfazem uma condição de pesquisa e descobre que o conjunto de linhas que satisfazem 
a condição foi alterado devido a outra transação confirmada recentemente.
--TRANSAÇÃO 2
START TRANSACTION ISOLATION LEVEL READ COMMITTED;
SELECT * FROM northwind.categories; -> estado atual com 1 a mnos na catgoria
--TRANSAÇÃO 1
START TRANSACTION ISOLATION LEVEL READ COMMITTED;
INSERT INTO northwind.categories VALUES (100, 'Teste', 'teste'); -> insere na categoria
SELECT * FROM northwind.categories;
COMMIT
--TRANSAÇÃO 2
SELECT * FROM northwind.categories; -> aparece uma categoria a mais antes do commit
COMMIT

-> Read uncommitted = Read committed  no PG
-> se fizer ambas T com Serializable - nao permite Phanton Read -  Leitura Fantasma
START TRANSACTION ISOLATION LEVEL Serializable -> sempre le a quatidade inicial de registros
-> se fizer ambas T com Repeatable read -  nao permite Phanton Read -  Leitura Fantasma
START TRANSACTION ISOLATION LEVEL Repeatable read -> sempre le a quantidade inicial de registros


-- ATIVIDADE 2.4
--SERIALIZATION ANOMALY- Anomalia de serialização
O resultado da confirmação bem-sucedida de um grupo de transações é inconsistente 
com todas as ordens possíveis de executar essas transações uma de cada vez.
-TRANSAÇÃO 2
START TRANSACTION ISOLATION LEVEL READ COMMITTED;
SELECT COUNT(categoryid) FROM northwind.categories WHERE categoryname like 'P%';qtd=1
--TRANSAÇÃO 1
START TRANSACTION ISOLATION LEVEL READ COMMITTED;
SELECT COUNT(categoryid) FROM northwind.categories WHERE categoryname like 'C%'; ->qtd =1
--TRANSAÇÃO 2
INSERT INTO northwind.categories VALUES (101, 'Casamento', 'teste');qtd=2
--TRANSAÇÃO 1
SELECT COUNT(categoryid) FROM northwind.categories WHERE categoryname like 'C%';->qtd =1
analise
INSERT INTO northwind.categories VALUES (100, 'Padaria', 'teste'); qtd=2
--TRANSAÇÃO 2
SELECT COUNT(categoryid) FROM northwind.categories WHERE categoryname like 'P%';qtd=1
analise
COMMIT
--TRANSAÇÃO 1
SELECT COUNT(categoryid) FROM northwind.categories WHERE categoryname like 'C%'; ->erro 
COMMIT / -- faz rollback deixa c com 2  e p permanece com 1

-> Read uncommitted = Read committed  no PG
-> se fizer ambas T com Repeatable read - também acontece SERIALIZATION ANOMALY- Anomalia de serialização
START TRANSACTION ISOLATION LEVEL Repeatable read ->acontence o mesmo 

-> se fizer ambas T com Serializable - nao permiteERIALIZATION ANOMALY-
START TRANSACTION ISOLATION LEVEL Serializable -> erro:
ERROR:  could not serialize access due to read/write dependencies among transactions
DETAIL:  Reason code: Canceled on identification as a pivot, during conflict out checking.
HINT:  The transaction might succeed if retried.


-- ATIVIDADE 2.5
-- Lost Update - Atualização Perdida

--TRANSAÇÃO 1
START TRANSACTION ISOLATION LEVEL READ COMMITTED;
SELECT * FROM northwind.products WHERE productid = 10;
--analise
UPDATE northwind.products SET unitprice = 50 WHERE productid = 10;
SELECT * FROM northwind.products WHERE productid = 10; -- unitprice = 50

--TRANSAÇÃO 2
START TRANSACTION ISOLATION LEVEL READ COMMITTED;
SELECT * FROM northwind.products WHERE productid = 10;
--analise  
UPDATE northwind.products SET unitprice = 100 WHERE productid = 10;
--Fica em espera -> não executa enquanto nao finalizar a transação 1

--TRANSAÇÃO 1
COMMIT -- unitprice = 50

--TRANSAÇÃO 2
SELECT * FROM northwind.products WHERE productid = 10; -- unitprice = 100
--analise
COMMIT -- unitprice = 100


-> Read uncommitted = Read committed  no PG
-> se fizer ambas T com Serializable - START TRANSACTION ISOLATION LEVEL Serializable: 
ERROR:  current transaction 2 is aborted, commands ignored until end of transaction block
-> se fizer ambas T com Repeatable read -  START TRANSACTION ISOLATION LEVEL Repeatable read: 
ERROR:  current transaction 2 is aborted, commands ignored until end of transaction block


---- ATIVIDADE 3.0
----Deadlock
--TRANSAÇÃO 1: START TRANSACTION
--TRANSAÇÃO 2: START TRANSACTION
--TRANSAÇÃO 1: UPDATE northwind.categories SET categoryid=15 WHERE categoryid=2;
--TRANSAÇÃO 2: UPDATE northwind.categories SET categoryid=15 WHERE categoryid=2;
--TRANSAÇÃO 1: UPDATE northwind.categories SET categoryid=15 WHERE categoryid=2;
--TRANSAÇÃO 2: SELECT DISTINCT categoryid FROM northwind.products;
               UPDATE northwind.categories SET description= ‘concorrência ativa’ WHERE categoryid = 4;
               COMMIT
--TRANSAÇÃO 1: COMMIT

---- ATIVIDADE 3.1
----Deadlock
--TRANSAÇÃO 1: START TRANSACTION
--TRANSAÇÃO 2: START TRANSACTION
--TRANSAÇÃO 1: UPDATE northwind.categories SET categoryid=15 WHERE categoryid=2;
--TRANSAÇÃO 2: UPDATE northwind.categories SET categoryid=15 WHERE categoryid=2;
--TRANSAÇÃO 1: SELECT DISTINCT categoryid FROM northwind.products;
--TRANSAÇÃO 2: UPDATE northwind.categories SET categoryid=15 WHERE categoryid=2;
--TRANSAÇÃO 1: UPDATE northwind.categories SET description= ‘concorrência ativa’ WHERE categoryid = 4;
               COMMIT
--TRANSAÇÃO 1: COMMIT