class Solution:
    def commonChars(self, words: List[str]) -> List[str]:
        common = [float('inf')] * 26

        for word in words:
            count = [0] * 26

            for ch in word:
                count[ord(ch) - ord('a')] += 1

            for i in range(26):
                common[i] = min(common[i], count[i])

        ans = []

        for i in range(26):
            for _ in range(common[i]):
                ans.append(chr(i + ord('a')))

        return ans