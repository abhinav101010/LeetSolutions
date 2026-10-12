class Solution:
    def findRelativeRanks(self, score: List[int]) -> List[str]:
# Useless thinking
        # score = sorted(score, reverse=True)
        # ans = []
        # for i in range(len(score)):
        #     if i == 0:
        #         ans.append("Gold Medal")
        #         continue
        #     if i == 1:
        #         ans.append("Silver Medal")
        #         continue
        #     if i == 2:
        #         ans.append("Bronze Medal")
        #         continue
            
        #     ans.append(str(i+1))
        # return ans
        

        topNums = sorted(score, reverse=True)

        newScore = []
        for num in score:
            rank = topNums.index(num)
            if rank == 0:
                newScore.append("Gold Medal")
            elif rank == 1:
                newScore.append("Silver Medal")
            elif rank == 2:
                newScore.append("Bronze Medal")
            else:
                newScore.append(str(rank + 1))
        return newScore