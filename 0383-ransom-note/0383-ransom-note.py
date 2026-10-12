class Solution:
    def canConstruct(self, ransomNote: str, magazine: str) -> bool:
        chars = {}
        for c in magazine:
            chars[c] = chars.get(c, 0) + 1

        for c in ransomNote:
            if chars.get(c,0) == 0:
                return False
            chars[c] -=1
        return True