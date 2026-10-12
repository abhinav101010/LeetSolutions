# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def increasingBST(self, root: Optional[TreeNode]) -> Optional[TreeNode]:
        nodes = []
        def dfs(root):
            if not root:
                return

            dfs(root.left)
            nodes.append(root)
            dfs(root.right)

        dfs(root)

        for i in range(len(nodes) - 1):
            nodes[i].left = None
            nodes[i].right = nodes[i + 1]

        nodes[-1].left = None
        nodes[-1].right = None

        return nodes[0]