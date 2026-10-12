# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def isUnivalTree(self, root: Optional[TreeNode]) -> bool:
        uniVal = root.val
        ans = True
        def dfs(root):
            nonlocal ans
            if not root: return
            if uniVal != root.val:
                ans = False
            if ans:
                dfs(root.left)
                dfs(root.right)

        dfs(root)
        return ans
        