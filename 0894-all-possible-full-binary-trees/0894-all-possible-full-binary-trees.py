# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def allPossibleFBT(self, n: int) -> list[TreeNode]:
        memo = {0: [], 1: [TreeNode(0)]}
        def dfs(x):
            if x in memo:
                return memo[x]
            res = []
            for left in range(1, x, 2):  # left subtree size (odd)
                right = x - 1 - left
                for left_tree in dfs(left):
                    for right_tree in dfs(right):
                        root = TreeNode(0)
                        root.left = left_tree
                        root.right = right_tree
                        res.append(root)
            memo[x] = res
            return res
        return dfs(n)
