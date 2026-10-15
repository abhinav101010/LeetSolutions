class Solution:
    def longestMountain(self, arr: list[int]) -> int:
        n = len(arr)
        ans = 0
        base = 0
        while base < n:
            end = base
            # climb up
            if end + 1 < n and arr[end] < arr[end + 1]:
                while end + 1 < n and arr[end] < arr[end + 1]:
                    end += 1
                # peak at end
                if end + 1 < n and arr[end] > arr[end + 1]:
                    while end + 1 < n and arr[end] > arr[end + 1]:
                        end += 1
                    ans = max(ans, end - base + 1)
            base = max(end, base + 1)
        return ans
