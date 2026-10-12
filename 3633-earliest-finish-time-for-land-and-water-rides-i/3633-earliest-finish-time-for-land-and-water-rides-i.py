class Solution:
    def earliestFinishTime(self, landStartTime: List[int], landDuration: List[int], waterStartTime: List[int], waterDuration: List[int]) -> int:
        ans = float("inf")
        for i in range(len(landStartTime)):
            landFinish = landStartTime[i] + landDuration[i]
            for j in range(len(waterStartTime)):
                finish = max(landFinish, waterStartTime[j]) + waterDuration[j]
                ans = min(ans, finish)

        for i in range(len(waterStartTime)):
            waterFinish = waterStartTime[i] + waterDuration[i]
            for j in range(len(landStartTime)):
                finish = max(waterFinish, landStartTime[j]) + landDuration[j]
                ans = min(ans, finish)
        return ans