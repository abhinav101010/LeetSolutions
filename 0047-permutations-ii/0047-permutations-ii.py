class Solution:
    def permuteUnique(self, nums: List[int]) -> List[List[int]]:
        ans = set()
        def permutation(arr, start):
            nonlocal ans
            if start == len(arr):
                ans.add(tuple(arr))
                return
            
            for i in range(start, len(arr)):
                arr[i],arr[start] = arr[start], arr[i]
                permutation(arr, start+1)
                arr[i],arr[start] = arr[start], arr[i]
        permutation(nums, 0)

        return list(ans)