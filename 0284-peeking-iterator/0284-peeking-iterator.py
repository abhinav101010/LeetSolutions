# Definition for an iterator.
# class Iterator:
#     def __init__(self, nums):
#         self.nums = nums
#         self.index = 0
#     
#     def hasNext(self):
#         return self.index < len(self.nums)
#     
#     def next(self):
#         val = self.nums[self.index]
#         self.index += 1
#         return val

class PeekingIterator:
    def __init__(self, iterator):
        self.iterator = iterator
        self.peeked = None
    
    def peek(self):
        if self.peeked is None:
            self.peeked = self.iterator.next()
        return self.peeked
    
    def next(self):
        if self.peeked is not None:
            val = self.peeked
            self.peeked = None
            return val
        return self.iterator.next()
    
    def hasNext(self):
        return self.peeked is not None or self.iterator.hasNext()