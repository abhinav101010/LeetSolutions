class Solution:
    def treeToDoublyList(self, root: 'Node') -> 'Node':
        if not root:
            return None
        self.first = None
        self.last = None
        
        def inorder(node):
            if not node:
                return
            inorder(node.left)
            if not self.first:
                self.first = node
                self.last = node
            else:
                self.last.right = node
                node.left = self.last
                self.last = node
            inorder(node.right)
        
        inorder(root)
        self.first.left = self.last
        self.last.right = self.first
        return self.first