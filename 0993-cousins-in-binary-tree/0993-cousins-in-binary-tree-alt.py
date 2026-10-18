# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
from collections import deque
class Solution:
    def isCousins(self, root, x, y):
        q = deque([(root, 0, 0)]) # (node, depth, parent)
        px = py = dx = dy = -1
        while q:
            node, depth, parent = q.popleft()
            if node.val == x:
                px, dx = parent, depth
            if node.val == y:
                py, dy = parent, depth
            if px != -1 and py != -1: break
            if node.left: q.append((node.left, depth+1, node.val))
            if node.right: q.append((node.right, depth+1, node.val))
        return dx == dy and px != py
