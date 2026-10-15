# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def splitBST(self, root: TreeNode, target: int) -> List[TreeNode]:
        if not root:
            return [None, None]
        if root.val <= target:
            # root belongs to left tree
            right_split = self.splitBST(root.right, target)
            root.right = right_split[0]
            return [root, right_split[1]]
        else:
            # root belongs to right tree
            left_split = self.splitBST(root.left, target)
            root.left = left_split[1]
            return [left_split[0], root]
