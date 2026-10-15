from typing import List

class LogSystem:
    def __init__(self):
        self.logs = []  # list of (timestamp_str, id)
        self.granularity = {
            "Year": 4,
            "Month": 7,
            "Day": 10,
            "Hour": 13,
            "Minute": 16,
            "Second": 19
        }

    def put(self, id: int, timestamp: str) -> None:
        self.logs.append((timestamp, id))

    def retrieve(self, start: str, end: str, granularity: str) -> List[int]:
        g = self.granularity[granularity]
        s = start[:g]
        e = end[:g]
        res = []
        for ts, id in self.logs:
            if s <= ts[:g] <= e:
                res.append(id)
        return res
