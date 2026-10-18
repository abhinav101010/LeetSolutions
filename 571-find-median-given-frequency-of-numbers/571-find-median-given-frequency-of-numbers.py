from typing import List


class Number:
    def __init__(self, num: int, frequency: int):
        self.num = num
        self.frequency = frequency


class Solution:
    def findMedian(self, numbers: List[Number]) -> float:
        if not numbers:
            return 0.0
        ns = sorted(numbers, key=lambda n: n.num)
        total = sum(n.frequency for n in ns)
        low = (total + 1) // 2
        high = (total + 2) // 2
        cum = 0
        medians = []
        for n in ns:
            start = cum + 1
            cum += n.frequency
            end = cum
            s = max(start, low)
            e = min(end, high)
            for _ in range(s, e + 1):
                medians.append(n.num)
        if not medians:
            return 0.0
        return sum(medians) / len(medians)
