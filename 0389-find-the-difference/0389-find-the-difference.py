class Solution:
    def findTheDifference(self, s: str, t: str) -> str:
        sCount = 0
        tCount = 0
        for c in s:
            sCount+=ord(c)
        for c in t:
            tCount+=ord(c)
        return chr(tCount-sCount)