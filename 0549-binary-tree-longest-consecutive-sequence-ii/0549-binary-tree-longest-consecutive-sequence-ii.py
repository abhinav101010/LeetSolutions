import sys
sys.setrecursionlimit(10**7)

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def longestConsecutive(self, root: TreeNode) -> int:
        self.ans = 0
        def dfs(node):
            if not node:
                return [0, 0]
            d1, d2 = 1, 1
            left = dfs(node.left)
            right = dfs(node.right)
            if node.left:
                if node.left.val == node.val + 1:
                    d1 = max(d1, left[0] + 1)
                if node.left.val == node.val - 1:
                    d2 = max(d2, left[1] + 1)
            if node.right:
                if node.right.val == node.val + 1:
                    d1 = max(d1, right[0] + 1)
                if node.right.val == node.val - 1:
                    d2 = max(d2, right[1] + 1)
            self.ans = max(self.ans, d1 + d2 - 1)
            return [d1, d2]
        dfs(root)
        return self.ans
