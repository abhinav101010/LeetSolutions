class Solution:
    def smallestPalindrome(self, s: str) -> str:
# Self thought and written code, Stand Proud
        charCount = {}
        for c in s:
            if c in charCount:
                charCount[c]+=1
            else:
                charCount[c]=1

        ans = ""
        addon = ""
        for key,value in charCount.items():
            if value%2==0:
                ans+=key*(value//2)
            else:
                ans+=key*((value-1)//2)
                addon = key
        ans = "".join(sorted(ans)) + addon + "".join(sorted(ans)[::-1])
        return ans
