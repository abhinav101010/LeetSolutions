from collections import defaultdict

class AllOne:
    def __init__(self):
        self.key_count = {}
        self.count_keys = defaultdict(set)
        self.min_count = 0
        self.max_count = 0
    
    def inc(self, key: str) -> None:
        old_count = self.key_count.get(key, 0)
        new_count = old_count + 1
        self.key_count[key] = new_count
        
        if old_count > 0:
            self.count_keys[old_count].discard(key)
            if not self.count_keys[old_count]:
                del self.count_keys[old_count]
                if self.min_count == old_count:
                    self.min_count = min(self.count_keys.keys()) if self.count_keys else 0
        
        self.count_keys[new_count].add(key)
        self.max_count = max(self.max_count, new_count)
        if self.min_count == 0 or new_count < self.min_count:
            self.min_count = new_count
    
    def dec(self, key: str) -> None:
        if key not in self.key_count:
            return
        
        old_count = self.key_count[key]
        new_count = old_count - 1
        
        self.count_keys[old_count].discard(key)
        if not self.count_keys[old_count]:
            del self.count_keys[old_count]
            if self.max_count == old_count:
                self.max_count = max(self.count_keys.keys()) if self.count_keys else 0
        
        if new_count == 0:
            del self.key_count[key]
            if not self.count_keys:
                self.min_count = 0
            else:
                self.min_count = min(self.count_keys.keys())
        else:
            self.key_count[key] = new_count
            self.count_keys[new_count].add(key)
            if self.min_count == 0 or new_count < self.min_count:
                self.min_count = new_count
    
    def getMaxKey(self) -> str:
        if not self.count_keys:
            return ""
        return next(iter(self.count_keys[self.max_count]))
    
    def getMinKey(self) -> str:
        if not self.count_keys:
            return ""
        return next(iter(self.count_keys[self.min_count]))