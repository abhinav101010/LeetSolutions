# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
from collections import deque
from typing import Optional

class Solution:
    def widthOfBinaryTree(self, root: Optional[TreeNode]) -> int:
        queue = deque([(root, 0)])
        max_width = 0
        while queue:
            left_idx = queue[0][1]
            size = len(queue)
            for _ in range(size):
                node, idx = queue.popleft()
                if node.left:
                    queue.append((node.left, idx * 2))
                if node.right:
                    queue.append((node.right, idx * 2 + 1))
            max_width = max(max_width, idx - left_idx + 1)
        return max_width