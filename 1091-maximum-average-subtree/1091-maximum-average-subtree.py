# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def maximumAverageSubtree(self, root):
        self.ans = 0
        def dfs(node):
            if not node:
                return (0, 0)
            s1, c1 = dfs(node.left)
            s2, c2 = dfs(node.right)
            total = s1 + s2 + node.val
            count = c1 + c2 + 1
            self.ans = max(self.ans, total / count)
            return (total, count)
        dfs(root)
        return self.ans
