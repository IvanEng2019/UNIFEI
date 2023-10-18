from mapeamento import Order
from mapeamento import OrderDetail
from mapeamento import Product
from mapeamento import Customer
from sqlalchemy.orm import Session
from sqlalchemy import *
from sqlalchemy.orm import sessionmaker

class DAOCrud():
    def getSession():
        engine = create_engine("postgresql+psycopg2://postgres:123@localhost:5432/postgres", echo=True)
        Session = sessionmaker(bind=engine)
        session = Session()
        return session

    def insere(sessao, obj):
        sessao.add(obj)

    def deleta(session, obj):
        session.delete(obj)

    def consultaProduto(session, id):
        prod = session.query(Product).filter(Product.productid == id).first()
        return prod


class DAOVendas():
    def relatorioVendas(session, id):
        query = session.query(Order.orderid, Order.customerid, Customer.companyname, Order.orderdate,
                              func.count(OrderDetail.orderid),
                              func.sum(OrderDetail.unitprice*OrderDetail.quantity-OrderDetail.discount)
                              )
        query = query.group_by(OrderDetail.orderid, Order.orderid, Order.customerid, Order.orderdate, Customer.companyname)
        results = query.filter(Order.orderid == id).first()
        print(results)
        return results
