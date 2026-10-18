# 2619-array-prototype-last

class Solution:
    def last(self, arr):
        """
        :type arr: List[int]
        :rtype: int
        """
        if not arr:
            return -1
        return arr[-1]
