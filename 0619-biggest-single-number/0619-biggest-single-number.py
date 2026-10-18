class MyNumber:
    def __init__(self, num):
        self.num = num

class Solution:
    def biggestSingleNumber(self, numbers):
        cnt = {}
        for n in numbers:
            cnt[n.num] = cnt.get(n.num, 0) + 1
        res = -1
        for k, v in cnt.items():
            if v == 1 and k > res:
                res = k
        return res
