# coding: utf-8
from sqlalchemy.orm import Session
from sqlalchemy import *
from sqlalchemy.orm import sessionmaker
from sqlalchemy.orm.exc import ObjectDeletedError
from sqlalchemy.orm.exc import NoResultFound
from sqlalchemy.orm.exc import StaleDataError
from mapeamento import OrderDetail
from DAO import DAOCrud
from DAO import DAOVendas

class manipulaBanco():
    def cadastraProduto(prod):
        try:
            sessao = DAOCrud.getSession()
            DAOCrud.insere(sessao, prod)
            sessao.commit()
            sessao.close()
            return 1
        except:
            return -1

    def deletaproduto(id):
        try:
            sessao = DAOCrud.getSession()
            prod = DAOCrud.consultaProduto(sessao, id)
            DAOCrud.deleta(sessao, prod)
            sessao.commit()
            sessao.close()
            return 1
        except:
            return -1;

    def consultaProduto(id):
        try:
            sessao = DAOCrud.getSession()
            sessao.expire_on_commit = False
            prod = DAOCrud.consultaProduto(sessao, id)
            sessao.commit()
            sessao.close()
            return prod
        except :
            return -1

    def atualizaProduto(id):
        try:
            sessao = DAOCrud.getSession()
            prod = DAOCrud.consultaProduto(sessao, id)
            prod.unitsinstock = prod.unitsinstock - 10
            sessao.commit()
            sessao.close()
            return 1
        except StaleDataError as error:
            return -1

    def cadastraVenda(pedido, listaProdutos):
        try:
            sessao = DAOCrud.getSession()
            DAOCrud.insere(sessao, pedido)
            for p in listaProdutos:
                DAOCrud.insere(sessao, p)
            sessao.commit()
            sessao.close()
            return 1
        except StaleDataError as error:
            return -1
    
    def relatorio(id):
        try:
            sessao = DAOCrud.getSession()
            result = DAOVendas.relatorioVendas(sessao, id)
            sessao.commit()
            sessao.close()
            return result
        except StaleDataError as error:
            return -1