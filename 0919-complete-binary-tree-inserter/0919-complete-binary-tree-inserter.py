class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class CBTInserter:
    def __init__(self, root: TreeNode):
        self.root = root
        self.tree = []
        stack = [root]
        while stack:
            node = stack.pop()
            self.tree.append(node)
            if node.left:
                stack.append(node.left)
            if node.right:
                stack.append(node.right)

    def insert(self, v: int) -> int:
        node = TreeNode(v)
        self.tree.append(node)
        n = len(self.tree)
        parent = self.tree[(n - 2) // 2]
        if n % 2 == 0:
            parent.left = node
        else:
            parent.right = node
        return parent.val

    def get_root(self) -> TreeNode:
        return self.root
