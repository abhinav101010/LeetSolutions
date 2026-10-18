class Solution:
    def numberOfChild(self, n, k):
        k, mod = divmod(k, n - 1)
        return n - mod - 1 if k & 1 else mod
