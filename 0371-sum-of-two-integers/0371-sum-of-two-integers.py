class Solution:
    def getSum(self, a: int, b: int) -> int:
        # return a+b
        # return sum([a,b])

        # Trying to do it bitwise
        # if a < 0:
        #     a = (1 << 32) ^ a

        # if b < 0:
        #     b = (1 << 32) ^ b

        # aBin = bin(a)[2:][::-1]
        # bBin = bin(b)[2:][::-1]

        # carry = False
        # ans = []

        # for i in range(32):
        #     abit = aBin[i] if i < len(aBin) else '0'
        #     bbit = bBin[i] if i < len(bBin) else '0'

        #     if abit == '0' and bbit == '0':
        #         if carry:
        #             ans.append('1')
        #         else:
        #             ans.append('0')
        #         carry = False

        #     elif abit != bbit:
        #         if carry:
        #             ans.append('0')
        #             carry = True
        #         else:
        #             ans.append('1')
        #             carry = False

        #     else:
        #         if carry:
        #             ans.append('1')
        #         else:
        #             ans.append('0')

        #         carry = True

        # result = int("".join(ans[::-1]), 2)

        # if result >= 2**31:
        #     result = ~(result ^ 0xFFFFFFFF)

        # return result

        mask = 0xFFFFFFFF

        a = a & mask
        b = b & mask

        while b != 0:
            carry = (a & b) << 1

            a = (a ^ b) & mask
            b = carry & mask

        if a & 0x80000000:
            a = ~(a ^ mask)

        return a