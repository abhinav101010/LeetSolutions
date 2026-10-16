class Solution:
    def minElement(self, nums):
        def dig_sum(x):
            s = 0
            while x:
                s += x % 10
                x //= 10
            return s
        m = min(nums)
        return dig_sum(m)
