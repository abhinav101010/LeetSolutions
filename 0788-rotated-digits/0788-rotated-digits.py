class Solution:
    def rotatedDigits(self, n: int) -> int:
        rotate = {
            "0":"0",
            "1":"1",
            "2":"5",
            "5":"2",
            "6":"9",
            "8":"8",
            "9":"6",
        }

        ans = 0
        for num in range(1, n+1):
            rotatedNum = ""
            valid = True
            for c in str(num):
                if c == "3" or c == "4" or c == "7":
                    valid = False
                    break
                rotatedNum += rotate[c]
            if valid and rotatedNum != "" and int(rotatedNum) != num:
                ans+=1
        return ans
