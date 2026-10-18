class User:
    def __init__(self, account, name):
        self.account = account
        self.name = name

class Transaction:
    def __init__(self, transId, account, amount, transactedOnDate):
        self.transId = transId
        self.account = account
        self.amount = amount
        self.transactedOnDate = transactedOnDate

class Solution:
    def bankAccountSummaryII(self, users, transactions):
        nameByAccount = {}
        for u in users:
            nameByAccount[u.account] = u.name
        balance = {}
        for t in transactions:
            balance[t.account] = balance.get(t.account, 0) + t.amount
        res = []
        for u in users:
            bal = balance.get(u.account)
            if bal is not None and bal > 10000:
                res.append([u.name, str(bal)])
        return res
