class SalesPerson:
    def __init__(self, salesId, name, salary, commissionRate, hireDate):
        self.salesId = salesId
        self.name = name
        self.salary = salary
        self.commissionRate = commissionRate
        self.hireDate = hireDate

class Company:
    def __init__(self, comId, name, city):
        self.comId = comId
        self.name = name
        self.city = city

class Order:
    def __init__(self, orderId, date, comId, salesId, amount):
        self.orderId = orderId
        self.date = date
        self.comId = comId
        self.salesId = salesId
        self.amount = amount

class Solution:
    def salesPerson(self, salesPersons, companies, orders):
        redComIds = set()
        for c in companies:
            if c.name == "RED":
                redComIds.add(c.comId)
        badSalesIds = set()
        for o in orders:
            if o.comId in redComIds:
                badSalesIds.add(o.salesId)
        res = []
        for s in salesPersons:
            if s.salesId not in badSalesIds:
                res.append(s.name)
        return res
