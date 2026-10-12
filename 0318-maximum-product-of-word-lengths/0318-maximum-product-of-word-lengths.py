class Solution:
    def maxProduct(self, words: List[str]) -> int:
        # self thought logic
        ans = 0

        for i in range(len(words)):
            for j in range(i + 1, len(words)):
                common = False
                for c in words[j]:
                    if c in words[i]:
                        common = True
                        break
                if not common:
                    ans = max(ans, len(words[i]) * len(words[j]))
        return ans