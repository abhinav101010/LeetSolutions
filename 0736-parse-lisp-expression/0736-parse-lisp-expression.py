class Solution:
    def evaluate(self, expression: str) -> int:
        def parse(s, i, scopes):
            if s[i] != '(':
                # parse atom: could be number or variable
                j = i
                while j < len(s) and s[j] != ' ' and s[j] != ')':
                    j += 1
                token = s[i:j]
                if token[0].isdigit() or token[0] == '-':
                    return int(token), j
                # variable
                for scope in reversed(scopes):
                    if token in scope:
                        return scope[token], j
                raise ValueError('unknown variable: ' + token)
            # '('
            i += 1  # skip '('
            if s[i] == 'l':  # let
                i += 4  # skip 'let'
                scopes.append({})
                while True:
                    # peek next char
                    if s[i] == '(' or s[i].isdigit() or s[i] == '-' or s[i].isalpha():
                        # could be variable or expression
                        # we need to parse variable name
                        j = i
                        while j < len(s) and s[j] != ' ':
                            j += 1
                        var = s[i:j]
                        if s[j] == ')':  # last expression
                            val, i = parse(s, j, scopes)
                            scopes.pop()
                            return val, i
                        # otherwise it's assignment
                        i = j
                        # parse expression for value
                        val, i = parse(s, i, scopes)
                        scopes[-1][var] = val
                        # skip space
                        while i < len(s) and s[i] == ' ':
                            i += 1
                    else:
                        # should not happen
                        break
            elif s[i] == 'a':  # add
                i += 4  # skip 'add'
                a1, i = parse(s, i, scopes)
                # skip space
                while i < len(s) and s[i] == ' ':
                    i += 1
                a2, i = parse(s, i, scopes)
                # skip ')'
                while i < len(s) and s[i] == ' ':
                    i += 1
                i += 1  # skip ')'
                return a1 + a2, i
            else:  # mult
                i += 5  # skip 'mult'
                a1, i = parse(s, i, scopes)
                while i < len(s) and s[i] == ' ':
                    i += 1
                a2, i = parse(s, i, scopes)
                while i < len(s) and s[i] == ' ':
                    i += 1
                i += 1  # skip ')'
                return a1 * a2, i
        val, _ = parse(expression, 0, [])
        return val
