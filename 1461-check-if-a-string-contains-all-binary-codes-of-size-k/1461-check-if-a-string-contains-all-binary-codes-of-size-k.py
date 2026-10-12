class Solution:
    def hasAllCodes(self, s: str, k: int) -> bool:
# Tried through subsets: ----
        # ans = True
        # def checkCode(s, curr, i):
        #     nonlocal ans
        #     if i == k:
        #         if curr not in s:
        #             ans = False
        #         return

        #     if ans:
        #         checkCode(s, curr+"0", i+1)
        #         checkCode(s, curr+"1", i+1)
        
        # checkCode(s, "", 0)
        # return ans

# Tried through Permutation :----
        # ans = True
        # def generate(bits, start):
        #     nonlocal ans
        #     if not ans:
        #         return

        #     if start == len(bits):
        #         if "".join(bits) not in s:
        #             ans = False
        #         return

        #     for c in ("0", "1"):
        #         bits[start] = c
        #         generate(bits, start + 1)
        # generate([""] * k, 0)
        # return ans

# Tried three methods
        subStrs = set()
        for i in range(len(s)-k+1):
            subStrs.add(s[i:i+k])
        print(subStrs)

        return len(subStrs) == 2**k