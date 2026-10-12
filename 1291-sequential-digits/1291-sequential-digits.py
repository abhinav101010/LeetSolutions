class Solution:
    def sequentialDigits(self, low: int, high: int) -> List[int]:
        # ans = []
        # for num in range(low, high + 1):
        #     s = str(num)
        #     valid = True
        #     for i in range(1, len(s)):
        #         if int(s[i]) != int(s[i - 1]) + 1:
        #             valid = False
        #             break
        #     if valid:
        #         ans.append(num)
        # return ans

        # Dono approch khud lagai h, Stand proud
        ans = [int("".join(str(i) for i in range(1, len(str(low)) + 1)))]

        while ans[-1] <= high:
            s = str(ans[-1])
            if s[-1] == "9":
                length = len(s) + 1
                if length > 9:
                    break
                ans.append(int("".join(str(i) for i in range(1, length + 1))))
            else:
                nextVal = ""
                for c in s:
                    nextVal += str(int(c) + 1)
                ans.append(int(nextVal))

        if ans[-1] > high: ans.pop()

        while ans and ans[0] < low:
            ans.pop(0)
        return ans