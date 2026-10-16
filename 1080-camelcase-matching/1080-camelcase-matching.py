class Solution:
    def camelMatch(self, queries, pattern):
        def match(q):
            i = 0
            for c in q:
                if i < len(pattern) and c == pattern[i]:
                    i += 1
                elif c.isupper():
                    return False
            return i == len(pattern)
        return [match(q) for q in queries]
