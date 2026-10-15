class Solution:
    def numMatchingSubseq(self, s: str, words: list[str]) -> int:
        def is_subseq(word):
            i = 0
            for ch in s:
                if i < len(word) and word[i] == ch:
                    i += 1
            return i == len(word)
        return sum(1 for w in words if is_subseq(w))
