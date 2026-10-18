class Solution:
    def relocateMarbles(
        self, nums, moveFrom, moveTo
    ):
        pos = set(nums)
        for f, t in zip(moveFrom, moveTo):
            pos.remove(f)
            pos.add(t)
        return sorted(pos)
