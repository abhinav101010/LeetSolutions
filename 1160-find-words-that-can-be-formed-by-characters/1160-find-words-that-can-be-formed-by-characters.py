class Solution:
    def countCharacters(self, words: List[str], chars: str) -> int:
        count = Counter(chars)
        ans = 0

        for word in words:
            wordCount = Counter(word)

            if all(wordCount[c] <= count[c] for c in wordCount):
                ans += len(word)

        return ans