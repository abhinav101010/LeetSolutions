# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def countNodes(self, root: Optional[TreeNode]) -> int:
# WTF?? what do you men i implement an solution less than O(n), maybe O(log n)??
        # ans = 0
        # def dfs(root):
        #     nonlocal ans
        #     if not root: return
        #     ans+=1
        #     dfs(root.left)
        #     dfs(root.right)
        # dfs(root)
        # return ans

        # def dfs(node):
        #     if not node:
        #         return 0
        #     return 1 + dfs(node.left) + dfs(node.right)
        # return dfs(root)


        if not root:
            return 0

        left = root
        right = root

        leftHeight = 0
        rightHeight = 0

        while left:
            leftHeight += 1
            left = left.left

        while right:
            rightHeight += 1
            right = right.right

        if leftHeight == rightHeight:
            return (1 << leftHeight) - 1

        return (
            1
            + self.countNodes(root.left)
            + self.countNodes(root.right)
        )
