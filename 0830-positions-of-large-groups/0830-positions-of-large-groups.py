class Solution:
    def largeGroupPositions(self, s: str) -> List[List[int]]:
        ans = []

        start, end = 0, -1
        for i in range(1, len(s)):
            if s[i] == s[i-1]:
                continue
            end = i-1
            if (end-start)+1 >= 3:
                ans.append([start,end])
            start = i
            
        end = len(s) - 1
        if end - start + 1 >= 3:
            ans.append([start, end])
        return ans