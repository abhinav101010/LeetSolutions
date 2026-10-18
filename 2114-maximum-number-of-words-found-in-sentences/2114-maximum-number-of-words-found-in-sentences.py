class Solution:
    def mostWordsFound(self, sentences) :
        return 1 + max(s.count(' ') for s in sentences)
