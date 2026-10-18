# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def smallestFromLeaf(self, root: TreeNode) -> str:
        self.ans = '~'
        def dfs(node, path):
            if not node: return
            path += chr(ord('a') + node.val)
            if not node.left and not node.right:
                self.ans = min(self.ans, path[::-1])
                return
            dfs(node.left, path)
            dfs(node.right, path)
        dfs(root, '')
        return self.ans
