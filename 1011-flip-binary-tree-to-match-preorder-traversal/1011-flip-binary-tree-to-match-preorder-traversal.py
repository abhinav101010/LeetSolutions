# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def flipMatchVoyage(self, root, voyage):
        self.res = []
        self.i = 0
        def dfs(node):
            if not node or self.i == len(voyage):
                return True
            if node.val != voyage[self.i]:
                return False
            self.i += 1
            if node.left and node.left.val == voyage[self.i]:
                return dfs(node.left) and dfs(node.right)
            if node.right and node.right.val == voyage[self.i]:
                self.res.append(node.val)
                return dfs(node.right) and dfs(node.left)
            return not node.left and not node.right
        if dfs(root):
            return self.res
        return [-1]
