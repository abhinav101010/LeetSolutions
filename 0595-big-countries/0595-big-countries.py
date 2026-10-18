class Solution:
    def big_countries(self, world):
        return [[w['name'], w['population'], w['area']] for w in world if w['area'] >= 3000000 or w['population'] >= 25000000]
