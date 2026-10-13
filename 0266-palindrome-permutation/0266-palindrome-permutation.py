class Solution:
    def canPermutePalindrome(self, s: str) -> bool:
        count = set()
        for c in s:
            if c in count:
                count.remove(c)
            else:
                count.add(c)
        return len(count) <= 1