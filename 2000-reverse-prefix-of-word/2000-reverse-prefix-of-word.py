class Solution:
    def reversePrefix(self, word, ch) -> str:
        i = word.find(ch)
        return word if i == -1 else word[i::-1] + word[i + 1 :]
