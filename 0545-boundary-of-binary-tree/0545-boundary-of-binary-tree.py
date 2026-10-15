# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

from typing import List

class Solution:
    def boundaryOfBinaryTree(self, root: TreeNode) -> List[int]:
        if not root:
            return []
        if not root.left and not root.right:
            return [root.val]
        left_boundary = []
        # left boundary excluding leaf
        node = root.left
        while node:
            if node.left or node.right:  # not a leaf
                left_boundary.append(node.val)
            if node.left:
                node = node.left
            else:
                node = node.right
        # leaves
        leaves = []
        def dfs(node):
            if not node:
                return
            if not node.left and not node.right:
                leaves.append(node.val)
                return
            dfs(node.left)
            dfs(node.right)
        dfs(root)
        # right boundary excluding leaf
        right_boundary = []
        node = root.right
        while node:
            if node.left or node.right:  # not a leaf
                right_boundary.append(node.val)
            if node.right:
                node = node.right
            else:
                node = node.left
        # combine
        return [root.val] + left_boundary + leaves + right_boundary[::-1]
