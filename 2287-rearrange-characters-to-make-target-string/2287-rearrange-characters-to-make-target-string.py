class Solution:
    def rearrangeCharacters(self, s, target):
        cnt1 = Counter(s)
        cnt2 = Counter(target)
        return min(cnt1[c] // v for c, v in cnt2.items())
