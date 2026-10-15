class Solution:
    def isNStraightHand(self, hand: list[int], W: int) -> bool:
        if len(hand) % W != 0:
            return False
        from collections import Counter
        cnt = Counter(hand)
        keys = sorted(cnt.keys())
        for k in keys:
            if cnt[k] > 0:
                need = cnt[k]
                for i in range(k, k + W):
                    if cnt[i] < need:
                        return False
                    cnt[i] -= need
        return True
