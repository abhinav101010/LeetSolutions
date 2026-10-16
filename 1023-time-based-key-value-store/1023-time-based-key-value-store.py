class TimeMap:
    def __init__(self):
        self.store = {}
    def set(self, key, value, timestamp):
        self.store.setdefault(key, []).append((timestamp, value))
    def get(self, key, timestamp):
        if key not in self.store: return ""
        arr = self.store[key]
        l,r = 0,len(arr)-1
        res = ""
        while l <= r:
            m = (l+r)//2
            if arr[m][0] <= timestamp:
                res = arr[m][1]; l = m+1
            else:
                r = m-1
        return res
