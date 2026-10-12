class Solution:
    def minOperations(self, s: str) -> int:
        changes1 = 0
        changes2 = 0

        for i in range(len(s)):
            # Pattern: 010101...
            if s[i] != str(i % 2):
                changes1 += 1

            # Pattern: 101010...
            if s[i] != str(1 - (i % 2)):
                changes2 += 1

        return min(changes1, changes2)