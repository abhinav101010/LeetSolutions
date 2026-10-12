# Definition for a NestedInteger
# class NestedInteger:
#     def __init__(self, value=None):
#         self.value = value
#         self.list = []
#     
#     def isInteger(self) -> bool:
#         return self.value is not None
#     
#     def getInteger(self) -> int:
#         return self.value
#     
#     def getList(self) -> List['NestedInteger']:
#         return self.list
#     
#     def add(self, elem: 'NestedInteger') -> None:
#         self.list.append(elem)

class Solution:
    def deserialize(self, s: str) -> NestedInteger:
        if not s or s[0] != '[':
            return NestedInteger(int(s))
        
        stack = []
        num = ""
        sign = 1
        
        for c in s:
            if c == '[':
                stack.append(NestedInteger())
            elif c == ']':
                if num:
                    stack[-1].add(NestedInteger(sign * int(num)))
                    num = ""
                    sign = 1
                if len(stack) > 1:
                    top = stack.pop()
                    stack[-1].add(top)
            elif c == ',':
                if num:
                    stack[-1].add(NestedInteger(sign * int(num)))
                    num = ""
                    sign = 1
            elif c == '-':
                sign = -1
            else:
                num += c
        
        return stack[-1] if stack else NestedInteger()