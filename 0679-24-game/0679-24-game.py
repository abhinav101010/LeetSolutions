import itertools
import math
import bisect

class Solution:
    def judgePoint24(self, cards: List[int]) -> bool:
        cards = [float(c) for c in cards]
        
        def dfs(nums):
            if len(nums) == 1:
                return abs(nums[0] - 24) < 1e-6
            for i in range(len(nums)):
                for j in range(len(nums)):
                    if i != j:
                        next_nums = []
                        for k in range(len(nums)):
                            if k != i and k != j:
                                next_nums.append(nums[k])
                        for op in ['+', '-', '*', '/']:
                            if (op == '+' or op == '*') and j > i:
                                continue
                            if op == '/' and nums[j] == 0:
                                continue
                            if op == '+':
                                next_nums.append(nums[i] + nums[j])
                            elif op == '-':
                                next_nums.append(nums[i] - nums[j])
                            elif op == '*':
                                next_nums.append(nums[i] * nums[j])
                            elif op == '/':
                                next_nums.append(nums[i] / nums[j])
                            if dfs(next_nums):
                                return True
                            next_nums.pop()
            return False
        
        return dfs(cards)