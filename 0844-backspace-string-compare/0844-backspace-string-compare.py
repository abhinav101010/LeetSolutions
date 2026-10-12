class Solution:
    def backspaceCompare(self, s: str, t: str) -> bool:
        str1 = ""
        for c in s:
            if c == "#":
                str1 = str1[:-1]
                continue
            str1+=c
        
        str2 = ""
        for c in t:
            if c == "#":
                str2 = str2[:-1]
                continue
            str2+=c

        return str1 == str2