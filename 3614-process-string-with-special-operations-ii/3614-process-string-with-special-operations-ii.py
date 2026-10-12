class Solution:
    def processStr(self, s: str, k: int) -> str:
        # ans = ""

        # for c in s:
        #     if c == "*": ans = ans[:-1]; continue;
        #     if c == "#": ans = ans+ans; continue;
        #     if c == "%": ans = ans[::-1]; continue;
        #     ans=ans+c 

        # if k >= len(ans): return "."
        # return ans[k]

        length = 0

        for c in s:
            if c == "*":
                if length > 0:
                    length -= 1
            elif c == "#":
                length *= 2
            elif c == "%":
                pass
            else:
                length += 1
        if k >= length:
            return "."

        # Work backwards
        for i in range(len(s) - 1, -1, -1):
            c = s[i]
            if c == "#":

                length //= 2
                k %= length
            elif c == "%":
                k = length - 1 - k
            elif c == "*":
                length += 1
                # We can't determine the deleted character here.
                # Continue moving backwards.
            else:
                # c is a normal character
                length -= 1
                if k == length:
                    return c
        return "."