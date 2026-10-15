class Solution:
    def flipgame(self, fronts: list[int], backs: list[int]) -> int:
        same = set()
        for f, b in zip(fronts, backs):
            if f == b:
                same.add(f)
        ans = float('inf')
        for f in fronts:
            if f not in same:
                ans = min(ans, f)
        for b in backs:
            if b not in same:
                ans = min(ans, b)
        return 0 if ans == float('inf') else ans
