class Solution:
    def findJudge(self, n: int, trust: List[List[int]]) -> int:
        trusts = [0] * (n + 1)
        trustedBy = [0] * (n + 1)

        for a, b in trust:
            trusts[a] += 1
            trustedBy[b] += 1

        for person in range(1, n + 1):
            if trusts[person] == 0 and trustedBy[person] == n - 1:
                return person

        return -1