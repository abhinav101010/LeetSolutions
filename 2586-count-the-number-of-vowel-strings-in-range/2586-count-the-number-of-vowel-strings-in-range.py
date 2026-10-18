class Solution:
    def vowelStrings(self, words, left, right):
        return sum(
            w[0] in 'aeiou' and w[-1] in 'aeiou' for w in words[left : right + 1]
        )
