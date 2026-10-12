# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def inorderTraversal(self, root: Optional[TreeNode]) -> List[int]:
        # Self thought and written code, Stand Proud
        def inorder(root):
            if not root: return []

            left = []
            right = []
            if root.left:
                left += inorder(root.left)
            if root.right:
                right += inorder(root.right)
            return left+[root.val]+right

        return inorder(root)