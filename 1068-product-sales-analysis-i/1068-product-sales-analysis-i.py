class Product:
    def __init__(self, productId, productName):
        self.productId = productId
        self.productName = productName

class Sale:
    def __init__(self, saleId, productId, year, quantity, price):
        self.saleId = saleId
        self.productId = productId
        self.year = year
        self.quantity = quantity
        self.price = price

class Solution:
    def productSalesAnalysisI(self, products, sales):
        pname = {}
        for p in products:
            pname[p.productId] = p.productName
        res = []
        for s in sales:
            pn = pname.get(s.productId)
            if pn is not None:
                res.append([pn, str(s.year), str(s.price)])
        return res
