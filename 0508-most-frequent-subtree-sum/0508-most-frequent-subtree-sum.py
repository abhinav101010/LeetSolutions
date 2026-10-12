# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

from collections import Counter
from typing import List, Optional

class Solution:
    def findFrequentTreeSum(self, root: Optional[TreeNode]) -> List[int]:
        count = Counter()
        
        def subtree_sum(node: Optional[TreeNode]) -> int:
            if not node:
                return 0
            s = node.val + subtree_sum(node.left) + subtree_sum(node.right)
            count[s] += 1
            return s
        
        subtree_sum(root)
        max_freq = max(count.values())
        return [s for s, freq in count.items() if freq == max_freq]