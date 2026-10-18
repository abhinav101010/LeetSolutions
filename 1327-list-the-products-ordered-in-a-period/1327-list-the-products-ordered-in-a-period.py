from typing import List


class Product:
    def __init__(self, product_id: int, product_name: str, product_category: str):
        self.product_id = product_id
        self.product_name = product_name
        self.product_category = product_category


class Order:
    def __init__(self, product_id: int, order_date: str, unit: int):
        self.product_id = product_id
        self.order_date = order_date
        self.unit = unit


class Solution:
    def productsOrdered(self, products: List[Product], orders: List[Order]) -> List[List[str]]:
        pname = {p.product_id: p.product_name for p in products}
        units = {}
        for o in orders:
            if "2020-02-01" <= o.order_date < "2020-03-01":
                units[o.product_id] = units.get(o.product_id, 0) + o.unit
        result = []
        for pid in sorted(units):
            if units[pid] >= 100 and pid in pname:
                result.append([pname[pid], str(units[pid])])
        return result
