class Solution:
    def isAlienSorted(self, words: list[str], order: str) -> bool:
        order_map = {ch: i for i, ch in enumerate(order)}
        def less_equal(w1, w2):
            for c1, c2 in zip(w1, w2):
                if c1 != c2:
                    return order_map[c1] < order_map[c2]
            return len(w1) <= len(w2)
        for i in range(len(words)-1):
            if not less_equal(words[i], words[i+1]):
                return False
        return True
