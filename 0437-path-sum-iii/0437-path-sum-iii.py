# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

from collections import defaultdict
from typing import Optional

class Solution:
    def pathSum(self, root: Optional[TreeNode], targetSum: int) -> int:
        self.count = 0
        prefix_sum = defaultdict(int)
        prefix_sum[0] = 1
        
        def dfs(node: Optional[TreeNode], current_sum: int):
            if not node:
                return
            
            current_sum += node.val
            self.count += prefix_sum[current_sum - targetSum]
            prefix_sum[current_sum] += 1
            
            dfs(node.left, current_sum)
            dfs(node.right, current_sum)
            
            prefix_sum[current_sum] -= 1
        
        dfs(root, 0)
        return self.count