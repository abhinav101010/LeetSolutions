class Solution:
    def uncommonFromSentences(self, s1: str, s2: str) -> List[str]:
        words = s1.split() + s2.split()

        count = {}

        for word in words:
            count[word] = count.get(word, 0) + 1

        ans = []

        for word in count:
            if count[word] == 1:
                ans.append(word)

        return ans