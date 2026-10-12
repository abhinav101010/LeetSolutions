class Solution:
    def pathExistenceQueries(self, n: int, nums: List[int], maxDiff: int, queries: List[List[int]]) -> List[bool]:
        group_ids = [0] * n
        curr_id = 0
        for i in range(1, n):
            if nums[i] - nums[i-1] > maxDiff:
                curr_id +=1
            group_ids[i] = curr_id

        ans = []
        for u,v in queries:
            ans.append(group_ids[u] == group_ids[v])
        return ans