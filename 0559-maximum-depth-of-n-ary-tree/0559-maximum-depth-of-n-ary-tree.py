"""
# Definition for a Node.
class Node:
    def __init__(self, val: Optional[int] = None, children: Optional[List['Node']] = None):
        self.val = val
        self.children = children
"""

class Solution:
    def maxDepth(self, root: 'Node') -> int:
        ans = 0
        def recurr(root, curr):
            nonlocal ans
            if not root: return
            ans = max(ans, curr)
            for r in root.children:
                recurr(r, curr+1)
        recurr(root, 1)
        return ans