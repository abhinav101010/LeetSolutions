class Solution:
    def pancakeSort(self, arr: list[int]) -> list[int]:
        res = []
        n = len(arr)
        for target in range(n, 1, -1):
            idx = arr.index(target)
            if idx == target - 1:
                continue
            if idx != 0:
                arr[:idx+1] = reversed(arr[:idx+1])
                res.append(idx+1)
            arr[:target] = reversed(arr[:target])
            res.append(target)
        return res
