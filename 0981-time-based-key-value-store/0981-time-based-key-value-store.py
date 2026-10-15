class TimeMap:
    def __init__(self):
        self.store = {}  # key -> list of (timestamp, value)
    def set(self, key: str, value: str, timestamp: int) -> None:
        if key not in self.store:
            self.store[key] = []
        self.store[key].append((timestamp, value))
    def get(self, key: str, timestamp: int) -> str:
        if key not in self.store:
            return ""
        arr = self.store[key]
        # binary search for largest timestamp <= given
        lo, hi = 0, len(arr) - 1
        res = ""
        while lo <= hi:
            mid = (lo + hi) // 2
            if arr[mid][0] <= timestamp:
                res = arr[mid][1]
                lo = mid + 1
            else:
                hi = mid - 1
        return res
