class Solution(object):
    def subtractProductAndSum(self, n):
        """
        :type n: int
        :rtype: int
        """

        product, add = 1, 0

        for c in str(n):
            product *= int(c)
            add += int(c)
        return product-add
        