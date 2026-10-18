class Solution:
    def removeVowels(self, s):
        return "".join(c for c in s if c not in "aeiou")
