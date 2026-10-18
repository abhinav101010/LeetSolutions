from typing import List, Optional


class Customer:
    def __init__(self, id: int, name: str):
        self.id = id
        self.name = name


class Order:
    def __init__(self, id: int, customerId: int):
        self.id = id
        self.customerId = customerId


class Solution:
    def customersWhoNeverOrder(self, customers: List[Customer], orders: List[Order]) -> List[str]:
        orderedIds = set(o.customerId for o in orders)
        return [c.name for c in customers if c.id not in orderedIds]
