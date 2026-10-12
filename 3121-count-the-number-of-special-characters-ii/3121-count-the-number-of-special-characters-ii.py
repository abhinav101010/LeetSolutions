class Solution:
    def numberOfSpecialChars(self, word: str) -> int:
        # ans = {}

        # for i in range(len(word)):
        #     upperChar = word.find(word[i].upper())
        #     if word[i].islower() and upperChar > i:
        #         ans.update({word[i]: upperChar})
        #     if word[i] in ans.keys() and upperChar < i:
        #         ans.pop(word[i])
        # return len(ans)

# Both approch written by self, just didnt kenw of .rfind method
        ans = 0
        for char in "abcdefghijklmnopqrstuvwxyz":
            if char in word and char.upper() in word:
                if word.rfind(char) < word.find(char.upper()):
                    ans+=1
        return ans