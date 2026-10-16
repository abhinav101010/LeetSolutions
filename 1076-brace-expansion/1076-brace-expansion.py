class Solution:
    def braceExpansionII(self, expression):
        expr = expression
        res = set()
        def parse(start):
            cur = ['']
            i = start
            while i < len(expr):
                c = expr[i]
                if c == '{':
                    j = i + 1
                    depth = 1
                    while depth:
                        if expr[j] == '{': depth += 1
                        elif expr[j] == '}': depth -= 1
                        j += 1
                    inner, i = parse(i+1)
                    cur = [a+b for a in cur for b in inner]
                elif c == '}':
                    return cur, i+1
                elif c == ',':
                    return cur, i+1
                else:
                    cur = [a+c for a in cur]
                    i += 1
            return cur, i
        words, _ = parse(0)
        return sorted(set(words))
