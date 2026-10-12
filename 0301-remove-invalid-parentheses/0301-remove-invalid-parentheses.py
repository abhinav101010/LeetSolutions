from typing import List

class Solution:
    def removeInvalidParentheses(self, s: str) -> List[str]:
        def is_valid(string):
            count = 0
            for c in string:
                if c == '(':
                    count += 1
                elif c == ')':
                    count -= 1
                    if count < 0:
                        return False
            return count == 0
        
        level = {s}
        while True:
            valid = list(filter(is_valid, level))
            if valid:
                return valid
            
            next_level = set()
            for string in level:
                for i in range(len(string)):
                    if string[i] in '()':
                        next_level.add(string[:i] + string[i+1:])
            level = next_level