from typing import List


class Orders:
    def __init__(self, order_number: int, customer_number: int):
        self.order_number = order_number
        self.customer_number = customer_number


class Solution:
    def largestOrders(self, orders: List[Orders]) -> List[List[str]]:
        cnt = {}
        for o in orders:
            cnt[o.customer_number] = cnt.get(o.customer_number, 0) + 1
        bestCust, bestCnt = -1, -1
        for c in sorted(cnt):
            if cnt[c] > bestCnt:
                bestCnt = cnt[c]
                bestCust = c
        if bestCust == -1:
            return []
        return [[str(bestCust)]]
