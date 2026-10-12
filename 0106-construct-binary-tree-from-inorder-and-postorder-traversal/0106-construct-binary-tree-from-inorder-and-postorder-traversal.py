# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def buildTree(self, inorder: List[int], postorder: List[int]) -> Optional[TreeNode]:
        if not postorder or not inorder:
            return None

        rootVal = postorder[-1]
        root = TreeNode(rootVal)
        mid = inorder.index(rootVal)
        root.left = self.buildTree(
            inorder[:mid],
            postorder[:mid]
        )

        root.right = self.buildTree(
            inorder[mid + 1:],
            postorder[mid:-1]
        )
        return root