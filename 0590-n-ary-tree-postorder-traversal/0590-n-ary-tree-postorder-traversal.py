"""
# Definition for a Node.
class Node:
    def __init__(self, val: Optional[int] = None, children: Optional[List['Node']] = None):
        self.val = val
        self.children = children
"""

class Solution:
    def postorder(self, root: 'Node') -> List[int]:
        if not root: return []
        def recurr(root):
            ans = []
            if root.children:
                for r in root.children:
                    ans = ans + recurr(r)
            return ans + [root.val]
        return recurr(root)

        