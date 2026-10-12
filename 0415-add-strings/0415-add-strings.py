class Solution:
    def addStrings(self, num1: str, num2: str) -> str:
        # return str(int(num1)+int(num2))

        # intData = {
        #     '0':0,
        #     '1':1,
        #     '2':2,
        #     '3':3,
        #     '4':4,
        #     '5':5,
        #     '6':6,
        #     '7':7,
        #     '8':8,
        #     '9':9
        # }
        # newNum1 = 0
        # newNum2 = 0
        # for c in num1:
        #     newNum1 = newNum1*10+ intData[c]
        # for c in num2:
        #     newNum2 = newNum2*10+ intData[c]

        # return str(newNum1+newNum2)


        i = len(num1) - 1
        j = len(num2) - 1

        carry = 0
        ans = ""

        while i >= 0 or j >= 0 or carry:
            n1 = int(num1[i]) if i >= 0 else 0
            n2 = int(num2[j]) if j >= 0 else 0

            total = n1 + n2 + carry

            ans = str(total % 10) + ans
            carry = total // 10

            i -= 1
            j -= 1

        return ans