# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def minCameraCover(self, root):
        selfans = 0
        def dfs(node):
            if not node:
                return 2  # covered
            left = dfs(node.left)
            right = dfs(node.right)
            if left == 0 or right == 0:
                selfans += 1
                return 1  # has camera
            if left == 1 or right == 1:
                return 2  # covered
            return 0  # not covered
        ans = dfs(root)
        if ans == 0:
            selfans += 1
        return selfans
