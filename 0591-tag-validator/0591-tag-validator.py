class Solution:
    def isValid(self, code: str) -> bool:
        n = len(code)
        if n == 0 or code[0] != '<':
            return False
        stack = []
        i = 0
        seen_tag = False
        while i < n:
            if code[i] == '<':
                if i + 1 >= n:
                    return False
                if code[i+1] == '!':
                    # CDATA
                    if not code.startswith('<![CDATA[', i):
                        return False
                    j = code.find(']]>', i + 9)
                    if j == -1:
                        return False
                    i = j + 3
                elif code[i+1] == '/':
                    # end tag
                    j = code.find('>', i + 2)
                    if j == -1:
                        return False
                    tag = code[i+2:j]
                    if not (1 <= len(tag) <= 9 and all(c.isupper() for c in tag)):
                        return False
                    if not stack or stack.pop() != tag:
                        return False
                    seen_tag = True
                    if not stack and j + 1 != n:
                        return False
                    i = j + 1
                else:
                    # start tag
                    j = code.find('>', i + 1)
                    if j == -1:
                        return False
                    tag = code[i+1:j]
                    if not (1 <= len(tag) <= 9 and all(c.isupper() for c in tag)):
                        return False
                    stack.append(tag)
                    i = j + 1
            else:
                i += 1
        return not stack and seen_tag
