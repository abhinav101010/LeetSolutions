class Solution:
    def toGoatLatin(self, sentence: str) -> str:
        vowels = "aeiouAEIOU"
        words = sentence.split()

        ans = []

        for i in range(len(words)):
            word = words[i]

            if word[0] not in vowels:
                word = word[1:] + word[0]

            word += "ma"
            word += "a" * (i + 1)

            ans.append(word)

        return " ".join(ans)