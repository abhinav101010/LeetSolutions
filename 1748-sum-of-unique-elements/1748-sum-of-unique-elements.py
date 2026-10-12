class Solution:
    def sumOfUnique(self, nums):
        count = {}

        for num in nums:
            count[num] = count.get(num, 0) + 1

        total = 0

        for num in count:
            if count[num] == 1:
                total += num

        return total