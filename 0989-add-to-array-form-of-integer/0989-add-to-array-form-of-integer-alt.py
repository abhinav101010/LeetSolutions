class Solution:
    def addToArrayForm(self, num, k):
        res = []
        for i in range(len(num)-1, -1, -1):
            s = num[i] + k
            k, r = divmod(s, 10)
            res.append(r)
        while k:
            k, r = divmod(k, 10)
            res.append(r)
        return res[::-1]
