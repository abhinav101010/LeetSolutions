# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def sumRootToLeaf(self, root):
        self.ans = 0
        def dfs(node, val):
            if not node:
                return
            val = (val << 1) | node.val
            if not node.left and not node.right:
                self.ans += val
                return
            dfs(node.left, val)
            dfs(node.right, val)
        dfs(root, 0)
        return self.ans
