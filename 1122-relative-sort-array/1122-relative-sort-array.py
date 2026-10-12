class Solution:
    def relativeSortArray(self, arr1: List[int], arr2: List[int]) -> List[int]:
        count = {}

        for num in arr1:
            count[num] = count.get(num, 0) + 1

        ans = []

        for num in arr2:
            ans.extend([num] * count[num])
            del count[num]

        for num in sorted(count):
            ans.extend([num] * count[num])

        return ans