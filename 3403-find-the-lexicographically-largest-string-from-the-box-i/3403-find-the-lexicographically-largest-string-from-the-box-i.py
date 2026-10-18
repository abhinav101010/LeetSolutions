class Solution:
    def answerString(self, word, numFriends) :
        if numFriends == 1:
            return word
        n = len(word)
        return max(word[i : i + n - (numFriends - 1)] for i in range(n))
