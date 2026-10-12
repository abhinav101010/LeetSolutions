"""
# Definition for a Node.
class Node:
    def __init__(self, val: int = 0, left: 'Node' = None, right: 'Node' = None, next: 'Node' = None):
        self.val = val
        self.left = left
        self.right = right
        self.next = next
"""

class Solution:
    def connect(self, root: 'Node') -> 'Node':
        # Self thought and implemented logic, Stand Proud
        levels = {}

        def checkLevels(root, level):
            if not root: return
            if level in levels:
                levels[level] += [root]
            else:
                levels[level] = [root]
            
            checkLevels(root.left, level+1)
            checkLevels(root.right, level+1)
        checkLevels(root, 1)

        for i in levels:
            nodes = levels[i]
            for i in range(len(nodes) - 1):
                nodes[i].next = nodes[i + 1]
            if nodes:
                nodes[-1].next = None

        return root