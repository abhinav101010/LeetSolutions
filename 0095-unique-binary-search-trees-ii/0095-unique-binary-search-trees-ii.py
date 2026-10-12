# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
from typing import List, Optional
from functools import lru_cache

class Solution:
    def generateTrees(self, n: int) -> List[Optional[TreeNode]]:
        if n == 0:
            return []
        
        @lru_cache(None)
        def generate(start: int, end: int) -> List[Optional[TreeNode]]:
            if start > end:
                return [None]
            
            result = []
            for root_val in range(start, end + 1):
                left_trees = generate(start, root_val - 1)
                right_trees = generate(root_val + 1, end)
                
                for left in left_trees:
                    for right in right_trees:
                        root = TreeNode(root_val)
                        root.left = left
                        root.right = right
                        result.append(root)
            
            return result
        
        return generate(1, n)