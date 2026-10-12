# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def buildTree(self, preorder: List[int], inorder: List[int]) -> Optional[TreeNode]:
# Self thinking
        # Convert preorder to levels
        # levels = {0:[]}
        # level = 0
        # for num in preorder:
        #     if len(levels[level]) == 2**level:
        #         level+=1
        #         levels[level] = []
        #     levels[level] += [num]
            
        # print(levels)

        if not preorder or not inorder:
            return None

        rootVal = preorder[0]
        root = TreeNode(rootVal)
        mid = inorder.index(rootVal)

        root.left = self.buildTree(
            preorder[1:mid + 1],
            inorder[:mid]
        )
        root.right = self.buildTree(
            preorder[mid + 1:],
            inorder[mid + 1:]
        )
        return root