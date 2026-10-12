# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
from typing import List, Optional

class Solution:
    def constructMaximumBinaryTree(self, nums: List[int]) -> Optional[TreeNode]:
        def build(l, r):
            if l > r:
                return None
            max_idx = l
            for i in range(l, r+1):
                if nums[i] > nums[max_idx]:
                    max_idx = i
            root = TreeNode(nums[max_idx])
            root.left = build(l, max_idx-1)
            root.right = build(max_idx+1, r)
            return root
        return build(0, len(nums)-1)