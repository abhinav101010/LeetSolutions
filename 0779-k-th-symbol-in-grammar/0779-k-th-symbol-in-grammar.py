class Solution:
    def kthGrammar(self, n: int, k: int) -> int:
        # return 1 if number of 1s in (k-1) is odd else 0
        return bin(k-1).count('1') % 2
