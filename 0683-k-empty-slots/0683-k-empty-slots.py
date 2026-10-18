from typing import List
from collections import deque

class Solution:
    def kEmptySlots(self, bulbs: List[int], k: int) -> int:
        n = len(bulbs)
        if n == 0:
            return -1
        # days[pos] = day when bulb at position pos (1-indexed) turns on
        days = [0] * (n + 1)  # 1-indexed positions
        for day, pos in enumerate(bulbs, start=1):
            days[pos] = day
        # we need to examine windows of size k+2 over positions 1..n
        window = k + 2
        if window > n:
            return -1
        # sliding window minimum of size k over days[2..n-1]? Actually interior length = k
        # We'll compute min for each starting index l (1-indexed) of interior of length k
        # interior for window [l, l+window-1] is positions l+1 .. l+window-2 = l+1 .. l+k
        # So we need min over days[l+1 .. l+k] for l from 1 to n - window + 1
        m = n - window + 1  # number of windows
        mins = [0] * (m + 1)  # 1-indexed for l
        dq = deque()  # stores indices of days, increasing
        # we will process array days[2..n-1]? Actually we need sliding window over days[2..n-1] of length k? 
        # Let's shift: define arr = days[1:] (1-indexed). We'll compute min for each segment of length k starting at index s (1-indexed) where s from 2 to n-k+1? 
        # Simpler: compute min over days[i..i+k-1] for i from 2 to n-k+1? Wait we need interior l+1..l+k where l from 1 to m.
        # So interior start = l+1, length k.
        # Let's compute min over days[i..i+k-1] for i from 2 to n-k+1? Actually when l=1, interior start=2, end=1+k.
        # When l=m, interior start=m+1, end=m+k = (n-window+1)+1 + k = n - window +2 + k = n - (k+2) +2 + k = n.
        # So interior start ranges from 2 to n-k+1? Let's test: n=5,k=1 => window=3,m=5-3+1=3. l=1..3.
        # interior start: l+1 => 2,3,4. interior length k=1 => just that position.
        # n-k+1 =5-1+1=5. So start up to 5? Actually we only need start up to 4. So we need start from 2 to n-k? 
        # Let's compute: interior end = l+k <= n? l <= m = n-window+1 => l+k <= n-window+1 + k = n - (k+2) +1 + k = n -1.
        # So interior end <= n-1. So interior start = l+1 ranges from 2 to (n-1)-k+1 = n-k.
        # So we need min over days[i..i+k-1] for i from 2 to n-k.
        # That's length (n-k-1) windows.
        # Number of windows m = n - window +1 = n - k -1.
        # Indeed m = n - k -1 matches.
        # So we can compute sliding window minimum of size k over array days[2..n-1] (indices 2..n-1 inclusive) length = n-2.
        # But we need windows of size k over that array, resulting in (n-2)-k+1 = n-k-1 = m windows.
        # Good.
        # Let's build list arr = days[2:n] (exclusive of n? actually up to n-1 inclusive). In Python slice days[2:n] gives indices 2..n-1.
        arr = days[2:n]  # length n-2
        # sliding window minimum of size k over arr
        dq.clear()
        min_arr = []  # min for each window start in arr
        for i, val in enumerate(arr):
            # remove from back while larger
            while dq and arr[dq[-1]] >= val:
                dq.pop()
            dq.append(i)
            # remove front if out of window size k
            if dq[0] <= i - k:
                dq.popleft()
            if i >= k - 1:
                min_arr.append(arr[dq[0]])
        # min_arr length = len(arr) - k +1 = (n-2)-k+1 = n-k-1 = m
        # min_arr[j] corresponds to window start index in arr = j, which corresponds to original position start = 2 + j.
        # That start = l+1? Since l from 1..m, interior start = l+1 = 2 + (l-1) = l+1. Indeed j = l-1.
        # So min_arr[l-1] = min of days[l+1 .. l+k]
        ans = float('inf')
        for l in range(1, m+1):
            interior_min = min_arr[l-1]
            left_day = days[l]
            right_day = days[l + k + 1]
            if interior_min > max(left_day, right_day):
                cand = max(left_day, right_day)
                if cand < ans:
                    ans = cand
        return ans if ans != float('inf') else -1
