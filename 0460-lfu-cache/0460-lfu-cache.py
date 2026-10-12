from collections import OrderedDict

class LFUCache:
    def __init__(self, capacity: int):
        self.capacity = capacity
        self.key_to_val = {}
        self.key_to_freq = {}
        self.freq_to_keys = {1: OrderedDict()}
        self.min_freq = 0

    def get(self, key: int) -> int:
        if key not in self.key_to_val:
            return -1
        self._update_freq(key)
        return self.key_to_val[key]

    def put(self, key: int, value: int) -> None:
        if self.capacity == 0:
            return
        if key in self.key_to_val:
            self.key_to_val[key] = value
            self._update_freq(key)
            return
        
        if len(self.key_to_val) >= self.capacity:
            evict_key, _ = self.freq_to_keys[self.min_freq].popitem(last=False)
            del self.key_to_val[evict_key]
            del self.key_to_freq[evict_key]
        
        self.key_to_val[key] = value
        self.key_to_freq[key] = 1
        if 1 not in self.freq_to_keys:
            self.freq_to_keys[1] = OrderedDict()
        self.freq_to_keys[1][key] = None
        self.min_freq = 1

    def _update_freq(self, key: int) -> None:
        freq = self.key_to_freq[key]
        del self.freq_to_keys[freq][key]
        if not self.freq_to_keys[freq] and freq == self.min_freq:
            self.min_freq += 1
        
        new_freq = freq + 1
        self.key_to_freq[key] = new_freq
        if new_freq not in self.freq_to_keys:
            self.freq_to_keys[new_freq] = OrderedDict()
        self.freq_to_keys[new_freq][key] = None