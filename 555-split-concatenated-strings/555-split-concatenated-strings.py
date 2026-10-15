from typing import List
from collections import Counter

class Solution:
    def splitConcat(self, strs: List[str]) -> bool:
        n = len(strs)
        # precompute splits for each string
        splits = []  # list of list of (left,right)
        for s in strs:
            cur = []
            for i in range(1, len(s)):
                cur.append((s[:i], s[i:]))
            splits.append(cur)
        # backtracking
        def backtrack(idx, left_cnt, right_cnt):
            if idx == n:
                # check if left_cnt == right_cnt
                return left_cnt == right_cnt
            for left, right in splits[idx]:
                # choose this split
                left_cnt[left] += 1
                right_cnt[right] += 1
                if backtrack(idx+1, left_cnt, right_cnt):
                    return True
                # undo
                left_cnt[left] -= 1
                if left_cnt[left] == 0:
                    del left_cnt[left]
                right_cnt[right] -= 1
                if right_cnt[right] == 0:
                    del right_cnt[right]
            return False
        return backtrack(0, Counter(), Counter())
