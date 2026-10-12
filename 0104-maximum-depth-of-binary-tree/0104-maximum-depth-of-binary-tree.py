# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def maxDepth(self, root: Optional[TreeNode]) -> int:
        ans = 0
        def dfs(root, i):
            nonlocal ans
            if not root:
                return
            ans = max(ans, i)
            dfs(root.left, i+1)
            dfs(root.right, i+1)

        if root:
            dfs(root, 1)
        return ans