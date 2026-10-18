class Solution:
    def canBeEqual(self, s1, s2) -> bool:
        return Counter(s1[::2]) == Counter(s2[::2]) and Counter(s1[1::2]) == Counter(
            s2[1::2]
        )
