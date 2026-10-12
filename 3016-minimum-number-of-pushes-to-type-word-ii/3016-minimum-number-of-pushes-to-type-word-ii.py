class Solution:
    def minimumPushes(self, word: str) -> int:
        count = {}

        for c in word:
            count[c] = count.get(c, 0) + 1

        frequencies = sorted(count.values(), reverse=True)

        ans = 0

        for i, freq in enumerate(frequencies):
            pushes = i // 8 + 1
            ans += freq * pushes

        return ans