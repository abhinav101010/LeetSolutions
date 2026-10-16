class Solution:
    def minSwaps(self, data):
        k = sum(data)
        if k <= 1:
            return 0
        # window of size k, count zeros (need to swap)
        zeros = sum(1 for x in data[:k] if x == 0)
        ans = zeros
        for i in range(k, len(data)):
            if data[i-k] == 0:
                zeros -= 1
            if data[i] == 0:
                zeros += 1
            ans = min(ans, zeros)
        return ans
