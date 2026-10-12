# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Codec:
    def serialize(self, root):
        """Encodes a tree to a single string."""
        def dfs(node):
            if not node:
                return "N"
            return str(node.val) + "," + dfs(node.left) + "," + dfs(node.right)
        return dfs(root)
    
    def deserialize(self, data):
        """Decodes your encoded data to tree."""
        vals = data.split(",")
        self.i = 0
        
        def dfs():
            if vals[self.i] == "N":
                self.i += 1
                return None
            node = TreeNode(int(vals[self.i]))
            self.i += 1
            node.left = dfs()
            node.right = dfs()
            return node
        
        return dfs()