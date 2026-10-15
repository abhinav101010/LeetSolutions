class Solution:
    def numSpecialEquivGroups(self, A: list[str]) -> int:
        seen = set()
        for s in A:
            even = []
            odd = []
            for i, ch in enumerate(s):
                if i % 2 == 0:
                    even.append(ch)
                else:
                    odd.append(ch)
            even.sort()
            odd.sort()
            seen.add((tuple(even), tuple(odd)))
        return len(seen)
