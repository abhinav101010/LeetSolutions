class Solution:
    def threeEqualParts(self, arr: list[int]) -> list[int]:
        n = len(arr)
        ones = sum(arr)
        if ones % 3 != 0:
            return [-1, -1]
        if ones == 0:
            return [0, n - 1]

        k = ones // 3
        p = 0
        for i, x in enumerate(arr):
            if x == 1:
                p += 1
                if p == 1:
                    first = i
                elif p == k + 1:
                    second = i
                elif p == 2 * k + 1:
                    third = i
                    break

        while third < n:
            if arr[first] == arr[second] == arr[third]:
                first += 1
                second += 1
                third += 1
            else:
                return [-1, -1]
        return [first - 1, second]
