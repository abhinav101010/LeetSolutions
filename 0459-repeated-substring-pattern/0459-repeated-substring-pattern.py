class Solution:
    def repeatedSubstringPattern(self, s: str) -> bool:
        # subStr = ""
        # for i in range(len(s)):
        #     subStr=subStr+s[i]
        #     if s.find(subStr, i)!=-1:
        #         return True
        # return False

        # for i in range(1, len(s)):
        #     if len(s) % i != 0:
        #         continue

        #     subStr = s[:i]

        #     if subStr * (len(s) // i) == s:
        #         return True

        # return False

        return s in (s + s)[1:-1]