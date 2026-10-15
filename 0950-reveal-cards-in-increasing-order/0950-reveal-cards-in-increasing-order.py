from collections import deque
class Solution:
    def deckRevealedIncreasing(self, deck: list[int]) -> list[int]:
        n = len(deck)
        deck.sort()
        res = [0]*n
        idx = deque(range(n))
        for card in deck:
            i = idx.popleft()
            res[i] = card
            if idx:
                idx.append(idx.popleft())
        return res
