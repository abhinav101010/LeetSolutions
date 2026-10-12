class Solution:
    def mapWordWeights(self, words: List[str], weights: List[int]) -> str:
        ans = ""

        for i in range(len(words)):
            wordWeight = 0
            for c in words[i]:
                wordWeight+=weights[ord(c) - ord('a')]
            ans += chr(ord('z') - (wordWeight%26))
        return ans