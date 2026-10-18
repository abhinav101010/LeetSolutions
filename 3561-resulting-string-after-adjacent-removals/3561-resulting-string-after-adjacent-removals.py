class Solution:
    def resultingString(self, s) :
        stk = []
        for c in s:
            if stk and abs(ord(c) - ord(stk[-1])) in (1, 25):
                stk.pop()
            else:
                stk.append(c)
        return "".join(stk)
