class Solution:
    def licenseKeyFormatting(self, s: str, k: int) -> str:
        ans = ""
        temp = k
        for c in s[::-1]:
            if c == '-': continue
            if temp == 0: 
                ans+='-'
                temp = k
            ans+=c
            temp-=1
        return ans[::-1].upper()
