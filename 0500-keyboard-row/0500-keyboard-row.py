class Solution:
    def findWords(self, words: List[str]) -> List[str]:
        rows = [
            set("qwertyuiop"),
            set("asdfghjkl"),
            set("zxcvbnm")
        ]

        ans = []

        for word in words:
            lowerWord = word.lower()

            for row in rows:
                if all(c in row for c in lowerWord):
                    ans.append(word)
                    break

        return ans