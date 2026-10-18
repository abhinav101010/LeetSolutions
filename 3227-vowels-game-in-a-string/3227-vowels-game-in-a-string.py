class Solution:
    def doesAliceWin(self, s):
        vowels = set("aeiou")
        return any(c in vowels for c in s)
