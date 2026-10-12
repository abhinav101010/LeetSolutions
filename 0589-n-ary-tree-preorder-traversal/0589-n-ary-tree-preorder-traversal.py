"""
# Definition for a Node.
class Node:
    def __init__(self, val: Optional[int] = None, children: Optional[List['Node']] = None):
        self.val = val
        self.children = children
"""

class Solution:
    def preorder(self, root: 'Node') -> List[int]:
        if not root: return []
        def recurr(root):
            ans = [root.val]
            if not root.children: return ans
            for r in root.children:
                ans.extend(recurr(r))
            return ans
        return recurr(root)
