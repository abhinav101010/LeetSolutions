# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def isCousins(self, root: Optional[TreeNode], x: int, y: int) -> bool:
        xDepth = yDepth = -1
        xParent = yParent = None
        def dfs(parent, root, k):
            nonlocal xDepth
            nonlocal yDepth
            nonlocal xParent
            nonlocal yParent
            if not root: return
            if root.val == x:
                xParent = parent
                xDepth = k
            if root.val == y:
                yParent = parent
                yDepth = k
            
            if xDepth == -1 or yDepth == -1:
                dfs(root, root.left, k+1)
                dfs(root, root.right, k+1)
        dfs(None, root, 0)
        return (xDepth == yDepth and xParent!=yParent)