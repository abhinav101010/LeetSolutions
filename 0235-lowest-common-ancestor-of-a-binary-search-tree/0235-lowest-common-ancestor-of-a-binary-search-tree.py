# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def lowestCommonAncestor(self, root: 'TreeNode', p: 'TreeNode', q: 'TreeNode') -> 'TreeNode':
        # pRoots = []
        # qRoots = []

        # def dfs(root, curr):
        #     nonlocal pRoots, qRoots

        #     if not root:
        #         return

        #     curr = curr + [root]

        #     if root == p:
        #         pRoots = curr

        #     if root == q:
        #         qRoots = curr

        #     dfs(root.left, curr)
        #     dfs(root.right, curr)

        # dfs(root, [])

        # for i in range(min(len(pRoots), len(qRoots))):
        #     if pRoots[i] != qRoots[i]:
        #         return pRoots[i - 1]

        # return pRoots[-1]

        while root:
            if p.val < root.val and q.val < root.val:
                root = root.left
            elif p.val > root.val and q.val > root.val:
                root = root.right
            else:
                return root