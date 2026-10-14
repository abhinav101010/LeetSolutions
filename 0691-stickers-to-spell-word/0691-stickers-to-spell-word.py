from typing import List
from collections import Counter

class Solution:
    def minStickers(self, stickers: List[str], target: str) -> int:
        # Preprocess stickers: count of each letter (only those in target)
        target_counter = Counter(target)
        # We only care about letters that are in target
        stickers_counter = []
        for s in stickers:
            cnt = Counter(s)
            # Keep only letters that are in target
            filtered = {ch: cnt[ch] for ch in cnt if ch in target_counter}
            if filtered:
                stickers_counter.append(filtered)
        # If no sticker has any letter from target, impossible
        if not stickers_counter:
            return -1
        # Memoization
        from functools import lru_cache
        @lru_cache(None)
        def dp(state_tuple):
            # state_tuple represents the remaining counts for each letter in target, in a fixed order
            # We'll use the order of letters as they appear in target_counter keys sorted
            if all(v == 0 for v in state_tuple):
                return 0
            # Convert tuple back to Counter for easier manipulation
            state = {}
            for ch, val in zip(sorted(target_counter.keys()), state_tuple):
                if val > 0:
                    state[ch] = val
            # Try each sticker
            ans = float('inf')
            for sticker in stickers_counter:
                # If the sticker has the first letter of the state (to reduce branching)
                # We can optimize by only considering stickers that have the first non-zero letter
                # Find the first letter in state
                first = None
                for ch in state:
                    if state[ch] > 0:
                        first = ch
                        break
                if first is None:
                    continue
                if first not in sticker:
                    continue  # skip sticker that doesn't help with the first letter
                new_state = list(state_tuple)
                for i, ch in enumerate(sorted(target_counter.keys())):
                    if ch in sticker:
                        new_state[i] = max(0, new_state[i] - sticker[ch])
                ans = min(ans, 1 + dp(tuple(new_state)))
            return ans
        # Initial state tuple
        initial = tuple(target_counter[ch] for ch in sorted(target_counter.keys()))
        res = dp(initial)
        return res if res != float('inf') else -1
