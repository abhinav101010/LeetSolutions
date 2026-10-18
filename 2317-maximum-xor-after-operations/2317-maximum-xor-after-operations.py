class Solution:
    def maximumXOR(self, nums) :
        return reduce(or_, nums)
