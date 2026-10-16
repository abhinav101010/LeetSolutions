# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def recoverFromPreorder(self, s):
        i = 0
        stack = []
        while i < len(s):
            depth = 0
            while i < len(s) and s[i] == '-':
                depth += 1
                i += 1
            val = 0
            while i < len(s) and s[i].isdigit():
                val = val * 10 + int(s[i])
                i += 1
            while len(stack) > depth:
                stack.pop()
            node = TreeNode(val)
            if stack:
                if not stack[-1].left:
                    stack[-1].left = node
                else:
                    stack[-1].right = node
            stack.append(node)
        return stack[0]
