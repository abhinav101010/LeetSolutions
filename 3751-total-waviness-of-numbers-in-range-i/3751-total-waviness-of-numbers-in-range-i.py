class Solution:
    def totalWaviness(self, num1: int, num2: int) -> int:
        ans = 0
        for num in range(num1, num2+1):
            strNum = str(num)
            peak = 0
            valley = 0
            for i in range(1,len(strNum)-1):
                if int(strNum[i-1]) < int(strNum[i]) > int(strNum[i+1]):
                    peak+=1
                if int(strNum[i-1]) > int(strNum[i]) < int(strNum[i+1]):
                    valley+=1
            ans += peak+valley
        return ans
