class Solution:
    def reorderSpaces(self, text: str) -> str:
        words = text.split()
        spaces = text.count(' ')

        if len(words) == 1:
            return words[0] + ' ' * spaces

        gap = spaces // (len(words) - 1)
        extra = spaces % (len(words) - 1)

        return (' ' * gap).join(words) + ' ' * extra