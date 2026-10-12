class Solution:
    def processStr(self, s: str) -> str:
        ans = ""

        for c in s:
            if c == "*": ans = ans[:-1]; continue;
            if c == "#": ans = ans+ans; continue;
            if c == "%": ans = ans[::-1]; continue;
            ans=ans+c 

        return ans