from decimal import *
from mapeamento import Product
from mapeamento import Order
from mapeamento import OrderDetail
from datetime import datetime

class View():
    def inicio(self):
        return self.menu()

    def menu(self):
        print("M E N U")
        print("1. Cadastrar um produto")
        print("2. Deletar um produto")
        print("3. Consultar um produto")
        print("4. Alterar dados de um produto")
        print("5. Cadastrar uma venda")
        print("6. Relatório resumido de uma venda")
        print("7. Sair")
        opcao = int(input("Digite a opcao desejada : "))
        return opcao


    def coletadadosproduto(self):
        productid = int(input('Digite o identificador o produto: '))
        productname = input('Digite o nome do produto: ')
        supplierid = int(input('Digite o identificador do fornecedor: '))
        categoryid = int(input('Digite o identificador da categoria: '))
        quantityperunit = input('Digite a quantidade de produto por embalagem: ')
        unitprice = Decimal(input('Digite o preço do produto: '))
        unitsinstock = int(input('Digite a quantidade de unidades no estoque: '))
        unitsonorder = int(input('Digite a quantidade de unidades disponíveis para venda: '))
        reorderlevel = int(input('Digite nível do produto: '))
        discontinued = input('O produto está descontinuado? ')
        prod = Product(
            productid=productid,
            productname=productname,
            supplierid=supplierid,
            categoryid=categoryid,
            quantityperunit=quantityperunit,
            unitprice=unitprice,
            unitsinstock=unitsinstock,
            unitsonorder=unitsonorder,
            reorderlevel=reorderlevel,
            discontinued=discontinued
        )
        return prod

    def coletadadosprodutoupdate(self, id):
        atributos = {1: 'productname', 2: 'supplierid', 3: 'categoryid', 4: 'quantityperunit', 5:'unitprice', 6: 'unitsinstock', 7:'unitsonorder', 8 : 'reorderlevel', 9: 'discontinued'}
        print("Digite: ")
        print("1 para nome do produto")
        print("2 para o identificador do fornecedor")
        print("3 para o identificador da categoria")
        print("4 para a quantidade de produto por embalagem")
        print("5 para o preco unitario")
        print("6 para a quantidade de produto no estoque")
        print("7 para a quantidade de produto disponivel para venda")
        print("8 para o nível do produto")
        print("9 para descontinuado")
        campo = int(input())
        valor = input("Digite o novo valor para o atributo: ")
        if ((campo==2) or (campo==3) or (campo==6) or (campo==7) or (campo == 8)):
            int(valor)
        elif (campo==4):
            Decimal(valor)
        return (atributos[campo], valor)

    def recebecodproduto(self):
        productid = int(input('Digite o identificador o produto: '))
        return productid

    def recebecodpedido(self):
        pedidoid = int(input('Digite o identificador do pedido: '))
        return pedidoid


    def imprimeproduto(self, prod):
        if (prod is not None):
            print("ID : ", prod.productid)
            print("Nome : ", prod.productname)
            print("Fornecedor : ", prod.supplierid)
            print("Categoria : ", prod.categoryid)
            print("Quantidade por embalagem : ", prod.quantityperunit)
            print("Preco Unitario :", prod.unitprice)
            print("Estoque : ", prod.unitsinstock)
            print("Disponiveis para venda : ", prod.unitsonorder)
            print("Nivel :", prod.reorderlevel)
            print("Descontinuado :", prod.discontinued)
        else:
            print("Consulta vazia")


    def imprimeRelatorio(self, registros):
        if(registros is None):
            print("A consulta não retornou registros")
        else:
            print("Identificador do Pedido : ", registros[0])
            print("Identificador do Fornecedor : ", registros[1])
            print("Nome do Fornecedor : ", registros[2])
            print("Data do Pedido : ", registros[3])
            print("Total de Produtos no Pedido : ", registros[4])
            print("Valor total do Pedido : ", registros[5])

    def coletadadospedido(self):
        orderid = input('Digite o identificador do pedido: ')
        customerid = input('Digite o identificador do cliente: ')
        employeeid = input('Digite o identificador do funcionario: ')
        orderdate = input('Digite a data do pedido (AAAA-MM-DD): ')
        requireddate = input('Digite a data do fechamento do pedido (AAAA-MM-DD): ')
        shippeddate = input('Digite a data do envio do pedido (AAAA-MM-DD): ')
        freight = input('Digite o valor do frete: ')
        shipname = input('Digite o local do envio: ')
        shipaddress = input('Digite o endereço: ')
        shipcity = input('Digite a cidade do envio: ')
        shipregion = input('Digite a regiao do envio: ')
        shippostalcode = input('Digite o CEP: ')
        shipcountry = input('Digite o país: ')
        shipperid = input('Digite o id do endereço de envio: ')
        year, month, day = map(int, orderdate.split('-'))
        orderdate = datetime(year, month, day)
        year, month, day = map(int, requireddate.split('-'))
        requireddate = datetime(year, month, day)
        year, month, day = map(int, shippeddate.split('-'))
        shippeddate = datetime(year, month, day)
        pedido = Order(
            orderid= int(orderid),
            customerid = int(customerid),
            employeeid = int(employeeid),
            orderdate = orderdate,
            requireddate = requireddate,
            shippeddate = shippeddate,
            freight = Decimal(freight),
            shipname = shipname,
            shipaddress = shipaddress,
            shipcity = shipcity,
            shipregion = shipregion,
            shippostalcode = shippostalcode,
            shipcountry = shipcountry,
            shipperid = int(shipperid)
        )
        return pedido

    def coletaprodutospedido(self, orderid):
        i = 1
        listaProdutos =[]
        while i != -1:
            print("Informe os produtos para o pedido ", orderid, " : ")
            productid = input('Digite o identificador do produto: ')
            unitprice = input('Digite valor do produto: ')
            quantity = input('Digite a quantidade comprada :  ')
            discount = input('Digite o valor do desconto: ')
            produtoPedido = OrderDetail(
                orderid = int(orderid),
                productid = int(productid),
                unitprice = Decimal(unitprice),
                quantity = int(quantity),
                discount = Decimal(discount)
            )
            listaProdutos.append(produtoPedido)
            i = int(input("Deseja continuar cadastrar produtos para esse pedido? (-1 para sair; 1 para continuar)"))
        return listaProdutos

    def coletadadospedidoupdate (self):
        pedidoid = int(input('Digite o codigo do pedido: '))
        productid = int(input('Digite o identificador o produto: '))
        quantidade = int(input('Digite a quantidade vendida: '))
        return [pedidoid, productid, quantidade]

    def imprimeStatus(self, status):
        if (status == 'sucesso'):
            print("Comando executado no banco de dados com sucesso")
        else:
            print(status)
