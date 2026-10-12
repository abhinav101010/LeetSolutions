# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def getMinimumDifference(self, root: Optional[TreeNode]) -> int:
        nums = []
        def dfs(root):
            if not root: return
            nums.append(root.val)
            dfs(root.left)
            dfs(root.right)
        dfs(root)
        ans = float("inf")
        for i in range(len(nums)):
            for j in range(i+1, len(nums)):
                ans=min(ans, abs(nums[i]-nums[j]))
        return ans
