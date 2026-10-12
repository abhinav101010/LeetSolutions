# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def findTilt(self, root: Optional[TreeNode]) -> int:
        tilt = 0

        def dfs(root):
            nonlocal tilt

            if not root:
                return 0

            leftSum = dfs(root.left)
            rightSum = dfs(root.right)

            tilt += abs(leftSum - rightSum)

            return root.val + leftSum + rightSum

        dfs(root)

        return tilt