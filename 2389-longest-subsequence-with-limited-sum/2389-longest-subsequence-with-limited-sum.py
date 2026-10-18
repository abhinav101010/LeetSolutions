class Solution:
    def answerQueries(self, nums, queries):
        nums.sort()
        s = list(accumulate(nums))
        return [bisect_right(s, q) for q in queries]
