class Solution:
    def fixedPoint(self, arr):
        for i, x in enumerate(arr):
            if i == x:
                return i
        return -1
