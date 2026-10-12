# Definition for a nested list iterator.
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

class NestedIterator:
    def __init__(self, nestedList: List[NestedInteger]):
        self.stack = []
        for item in reversed(nestedList):
            self.stack.append(item)
    
    def next(self) -> int:
        return self.stack.pop().getInteger()
    
    def hasNext(self) -> bool:
        while self.stack:
            top = self.stack[-1]
            if top.isInteger():
                return True
            self.stack.pop()
            for item in reversed(top.getList()):
                self.stack.append(item)
        return False