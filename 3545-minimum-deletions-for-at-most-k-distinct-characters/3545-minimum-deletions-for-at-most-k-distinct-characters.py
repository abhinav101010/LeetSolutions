class Solution:
    def minDeletion(self, s, k) :
        return sum(sorted(Counter(s).values())[:-k])
