class Solution:
    def countAndSay(self, n: int) -> str:
        
        def countNext(numStr, i):
            if i == n: return numStr

            res = ""
            count = 1
            for j in range(1, len(numStr)):
                if numStr[j] == numStr[j-1]:
                    count+=1
                else:
                    res = res + str(count) + numStr[j-1]
                    count = 1
            res += str(count) + numStr[-1]
            return countNext(res, i+1)

        return countNext("1",1)