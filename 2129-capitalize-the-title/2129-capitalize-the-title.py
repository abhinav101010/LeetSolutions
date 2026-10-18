class Solution:
    def capitalizeTitle(self, title):
        words = [w.lower() if len(w) < 3 else w.capitalize() for w in title.split()]
        return " ".join(words)
