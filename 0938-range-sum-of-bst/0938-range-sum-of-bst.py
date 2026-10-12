# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def rangeSumBST(self, root: Optional[TreeNode], low: int, high: int) -> int:
        ans = 0
        def dfs(root):
            nonlocal ans
            if not root: return
            ans+=root.val if low <= root.val <= high else 0
            dfs(root.left)
            dfs(root.right)
        dfs(root)
        return ans