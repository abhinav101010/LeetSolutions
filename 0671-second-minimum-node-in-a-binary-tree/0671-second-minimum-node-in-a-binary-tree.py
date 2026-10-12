# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def findSecondMinimumValue(self, root: Optional[TreeNode]) -> int:
        nums = set()

        def dfs(root):
            if not root:
                return

            nums.add(root.val)

            dfs(root.left)
            dfs(root.right)

        dfs(root)

        if len(nums) < 2:
            return -1

        return sorted(nums)[1]