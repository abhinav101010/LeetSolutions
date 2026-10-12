import random
from collections import defaultdict

class RandomizedCollection:
    def __init__(self):
        self.nums = []
        self.val_to_indices = defaultdict(set)
    
    def insert(self, val: int) -> bool:
        self.val_to_indices[val].add(len(self.nums))
        self.nums.append(val)
        return len(self.val_to_indices[val]) == 1
    
    def remove(self, val: int) -> bool:
        if not self.val_to_indices[val]:
            return False
        
        idx = self.val_to_indices[val].pop()
        last = self.nums[-1]
        self.nums[idx] = last
        self.val_to_indices[last].add(idx)
        self.val_to_indices[last].discard(len(self.nums) - 1)
        self.nums.pop()
        return True
    
    def getRandom(self) -> int:
        return random.choice(self.nums)