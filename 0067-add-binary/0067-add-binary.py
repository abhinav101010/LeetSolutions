class Solution:
    def addBinary(self, a: str, b: str) -> str:
        # Binary addition is used here 

        # ans = ""
        # carry = 0
        # a,b = a[::-1], b[::-1]

        # for i in range(max(len(a), len(b))):
        #     digitA = int(a[i]) if i < len(a) else 0
        #     digitB = int(b[i]) if i < len(b) else 0

        #     total = digitA+digitB+carry
        #     ans = str(total%2) + ans
        #     carry = total // 2

        # if carry: ans = "1"+ans
        # return ans


        # I wrote fucking both code, because i didnt knew method bin exists
        return bin(int(a,2)+int(b,2))[2:]
        