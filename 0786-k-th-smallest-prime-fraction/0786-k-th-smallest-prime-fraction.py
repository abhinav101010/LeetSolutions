class Solution:
    def kthSmallestPrimeFraction(self, arr: list[int], k: int) -> list[int]:
        n = len(arr)
        left = 0.0
        right = 1.0
        while right - left > 1e-9:
            mid = (left + right) / 2.0
            # count number of fractions <= mid
            count = 0
            # also track the max fraction <= mid to return as answer
            max_frac = 0
            num = 0
            den = 1
            j = n - 1
            for i in range(n):
                while j >= 0 and arr[i] > mid * arr[j]:
                    j -= 1
                if j < 0:
                    break
                count += j + 1
                # update max fraction
                if j >= 0 and arr[i] * den > num * arr[j]:
                    num = arr[i]
                    den = arr[j]
            if count < k:
                left = mid
            else:
                right = mid
                # if count == k, we have answer in num/den
        # after binary search, left/right approx answer; we need to return exact fraction
        # recompute using the same method to get the fraction with count >= k and maximal fraction <= left?
        # Instead we can return [num, den] from last iteration where count >= k.
        # We'll store best when count >= k.
        # Let's redo with storing.
        left = 0.0
        right = 1.0
        best_num = 0
        best_den = 1
        while right - left > 1e-9:
            mid = (left + right) / 2.0
            count = 0
            j = n - 1
            cur_num = 0
            cur_den = 1
            for i in range(n):
                while j >= 0 and arr[i] > mid * arr[j]:
                    j -= 1
                if j < 0:
                    break
                count += j + 1
                if j >= 0:
                    # fraction arr[i]/arr[j]
                    if arr[i] * cur_den > cur_num * arr[j]:
                        cur_num = arr[i]
                        cur_den = arr[j]
            if count < k:
                left = mid
            else:
                right = mid
                best_num = cur_num
                best_den = cur_den
        return [best_num, best_den]
