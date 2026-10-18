from typing import List
from collections import defaultdict
import bisect
import math
import functools
import heapq

class Log:
    def __init__(self, id: int, num: str):
        self.id = id
        self.num = num

class Solution:
    def consecutiveNumbers(self, logs: List[Log]) -> List[str]:
        if len(logs) < 3:
            return []
        # Sort logs by id
        sorted_logs = sorted(logs, key=lambda x: x.id)
        result = []
        for i in range(len(sorted_logs) - 2):
            if sorted_logs[i].num == sorted_logs[i + 1].num and \
               sorted_logs[i + 1].num == sorted_logs[i + 2].num:
                num_val = sorted_logs[i].num
                # Avoid duplicates in result
                if not result or result[-1] != num_val:
                    result.append(num_val)
                # Skip to i+2
                # But in for loop, need to handle - we'll just continue; 
                # but to be efficient, we could adjust - easier to just continue
        return result
