class Solution:
    def countConsistentStrings(self, allowed: str, words: list[str]) -> int:
        allowed_set = set(allowed)
        count = 0

        for word in words:
            if all(ch in allowed_set for ch in word):
                count += 1

        return count