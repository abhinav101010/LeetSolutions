class Product:
    def __init__(self, product_id, store1, store2, store3):
        self.product_id = product_id
        self.store1 = store1
        self.store2 = store2
        self.store3 = store3

class Solution:
    def rearrange(self, products):
        res = []
        for p in products:
            if p.store1 is not None:
                res.append((p.product_id, 'store1', p.store1))
            if p.store2 is not None:
                res.append((p.product_id, 'store2', p.store2))
            if p.store3 is not None:
                res.append((p.product_id, 'store3', p.store3))
        return res
