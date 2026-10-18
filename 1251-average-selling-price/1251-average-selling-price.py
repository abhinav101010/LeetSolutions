from typing import List


class Price:
    def __init__(self, product_id: int, start_date: str, end_date: str, price: int):
        self.product_id = product_id
        self.start_date = start_date
        self.end_date = end_date
        self.price = price


class Unit:
    def __init__(self, product_id: int, purchase_date: str, units: int):
        self.product_id = product_id
        self.purchase_date = purchase_date
        self.units = units


class Result:
    def __init__(self, product_id: int, average_price: float):
        self.product_id = product_id
        self.average_price = average_price


class Solution:
    def averageSellingPrice(self, prices: List[Price], units: List[Unit]) -> List[Result]:
        avg = {p.product_id: 0.0 for p in prices}
        byProd = {}
        for u in units:
            byProd.setdefault(u.product_id, []).append(u)
        for pid, lst in byProd.items():
            if pid not in avg:
                avg[pid] = 0.0
            sumPu = 0.0
            sumU = 0.0
            for u in lst:
                for p in prices:
                    if p.product_id == pid and p.start_date <= u.purchase_date <= p.end_date:
                        sumPu += p.price * u.units
                        sumU += u.units
                        break
            if sumU > 0:
                avg[pid] = round(sumPu / sumU * 100) / 100.0
            else:
                avg[pid] = 0.0
        return [Result(pid, val) for pid, val in avg.items()]
