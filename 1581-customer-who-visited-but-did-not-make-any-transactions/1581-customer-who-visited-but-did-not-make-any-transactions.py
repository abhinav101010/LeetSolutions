from typing import List


class Visit:
    def __init__(self, visit_id: int, customer_id: int):
        self.visit_id = visit_id
        self.customer_id = customer_id


class Transaction:
    def __init__(self, transaction_id: int, visit_id: int, amount: int):
        self.transaction_id = transaction_id
        self.visit_id = visit_id
        self.amount = amount


class Result:
    def __init__(self, customer_id: int, count_no_trans: int):
        self.customer_id = customer_id
        self.count_no_trans = count_no_trans


class Solution:
    def customerVisitsWithoutTransactions(self, visits: List[Visit], transactions: List[Transaction]) -> List[Result]:
        withTrans = set(t.visit_id for t in transactions)
        cnt = {}
        for v in visits:
            if v.visit_id not in withTrans:
                cnt[v.customer_id] = cnt.get(v.customer_id, 0) + 1
        return [Result(cid, c) for cid, c in cnt.items()]
