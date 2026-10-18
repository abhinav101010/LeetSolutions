from typing import List
from collections import defaultdict

class Activities:
    def __init__(self, sell_date: str, product: str):
        self.sell_date = sell_date
        self.product = product

class Result:
    def __init__(self, sell_date: str, num_sold: int, products: str):
        self.sell_date = sell_date
        self.num_sold = num_sold
        self.products = products

class Solution:
    def groupSoldProducts(self, activities: List[Activities]) -> List[Result]:
        date_to_products = defaultdict(set)
        for a in activities:
            date_to_products[a.sell_date].add(a.product)
        results = []
        for date in sorted(date_to_products.keys()):
            prod_set = date_to_products[date]
            prod_list = sorted(list(prod_set))
            products_str = ','.join(prod_list)
            results.append(Result(date, len(prod_list), products_str))
        return results
