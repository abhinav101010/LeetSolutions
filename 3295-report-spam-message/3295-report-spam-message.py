class Solution:
    def reportSpam(self, message, bannedWords):
        s = set(bannedWords)
        return sum(w in s for w in message) >= 2
