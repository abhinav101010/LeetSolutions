from typing import List

class Solution:
    def findMinMoves(self, machines: List[int]) -> int:
        total = sum(machines)
        n = len(machines)
        if total % n != 0:
            return -1
        avg = total // n
        
        max_moves = 0
        balance = 0
        for m in machines:
            balance += m - avg
            max_moves = max(max_moves, abs(balance), m - avg)
        
        return max_moves