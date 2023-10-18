from view import View
from mapeamento import Product
from mapeamento import Order
from mapeamento import OrderDetail
from model import manipulaBanco
from datetime import datetime


class Controle:
    def inicio(self):
        opcao = self.view.inicio()

        while opcao != 7:
            if opcao == 1:
                prod = self.view.coletadadosproduto()
                status = manipulaBanco.cadastraProduto(prod)
                self.view.imprimeStatus(status)
            if opcao == 2:
                id = self.view.recebecodproduto()
                status = manipulaBanco.deletaproduto(id)
                self.view.imprimeStatus(status)
            if opcao == 3:
                id = self.view.recebecodproduto()
                prod = manipulaBanco.consultaProduto(id)
                if ((prod is not None) and (prod != -1)):
                    self.view.imprimeproduto(prod)
                else:
                    self.view.imprimeStatus(-1)
            if opcao == 4:
                id = self.view.recebecodproduto()
                prod = manipulaBanco.consultaProduto(id)
                if (prod is not None):
                    status = manipulaBanco.atualizaProduto(id)
                    self.view.imprimeStatus(status)
            if opcao == 5:
                pedido = self.view.coletadadospedido()
                produtosPedido = self.view.coletaprodutospedido(pedido.orderid)
                status = manipulaBanco.cadastraVenda(pedido, produtosPedido)
                self.view.imprimeStatus(status)
            if opcao == 6:
                id = self.view.recebecodproduto()
                result = manipulaBanco.relatorio(id)
                self.view.imprimeRelatorio(result)
            opcao = self.view.menu()

    def __init__(self):
        self.view = View()

if __name__ == "__main__":
    main = Controle()
    main.inicio()