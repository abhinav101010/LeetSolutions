# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def recoverTree(self, root: Optional[TreeNode]) -> None:
        """
        Do not return anything, modify root in-place instead.
        """
        first = None
        second = None
        prev = None
    
        def in_order(node):
            nonlocal first, second, prev
            if not node:
                return
            in_order(node.left)
            if prev and prev.val > node.val:
                if first is None:
                    first = prev
                second = node

            prev = node
            in_order(node.right)
    
        in_order(root)
        first.val, second.val = second.val, first.val
