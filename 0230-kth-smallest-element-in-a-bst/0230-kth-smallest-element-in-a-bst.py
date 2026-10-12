# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def kthSmallest(self, root: Optional[TreeNode], k: int) -> int:
        elements = []
        def dfs(root):
            nonlocal elements
            if not root: return
            elements.append(root.val)
            dfs(root.left)
            dfs(root.right)
        dfs(root)
        elements.sort()
        return elements[k-1]