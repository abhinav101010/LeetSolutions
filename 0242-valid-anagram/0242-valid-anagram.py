class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        if len(t) != len(s): return False
        s = list(s)
        for c in t:
            try:
                s.remove(c)
            except ValueError:
                return False
        return True