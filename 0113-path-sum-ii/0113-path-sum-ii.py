# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def pathSum(self, root: Optional[TreeNode], targetSum: int) -> List[List[int]]:
        ans = []
        def checkLeafSum(root, sum, curr):
            if not root:
                return

            if sum+root.val == targetSum and not root.left and not root.right:
                ans.append(curr+[root.val])
                return

            checkLeafSum(root.left, sum+root.val, curr+[root.val])
            checkLeafSum(root.right, sum+root.val, curr+[root.val])

        checkLeafSum(root, 0, [])
        return ans