class Solution:
    def minimumLengthEncoding(self, words: list[str]) -> int:
        # Remove duplicates
        words = list(set(words))
        # Sort by length descending so that longer words first
        words.sort(key=len, reverse=True)
        # Use a set to store seen suffixes
        seen = set()
        res = 0
        for w in words:
            if w in seen:
                continue
            # add all suffixes of w to seen
            for i in range(len(w)):
                seen.add(w[i:])
            res += len(w) + 1  # word plus '#'
        return res
