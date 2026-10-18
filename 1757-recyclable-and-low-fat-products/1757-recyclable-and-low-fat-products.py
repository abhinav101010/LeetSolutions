from typing import List


class Product:
    def __init__(self, product_id: int, low_fats: str, recyclable: str):
        self.product_id = product_id
        self.low_fats = low_fats
        self.recyclable = recyclable


class Solution:
    def recyclableProducts(self, products: List[Product]) -> List[List[str]]:
        result = []
        for p in products:
            if p.low_fats == "Y" and p.recyclable == "Y":
                result.append([str(p.product_id)])
        return result
