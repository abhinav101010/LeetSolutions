class Solution:
    def getXORSum(self, arr1, arr2):
        a = reduce(xor, arr1)
        b = reduce(xor, arr2)
        return a & b
