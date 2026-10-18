from collections import deque
class Solution:
    def deckRevealedIncreasing(self, deck):
        n = len(deck)
        deck.sort()
        q = deque(range(n))
        ans = [0]*n
        for card in deck:
            idx = q.popleft()
            ans[idx] = card
            if q:
                q.append(q.popleft())
        return ans
