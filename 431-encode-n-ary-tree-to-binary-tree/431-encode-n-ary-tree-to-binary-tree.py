# Definition for a Node.
class Node:
    def __init__(self, val=None, children=None):
        self.val = val
        self.children = children if children is not None else []

# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Codec:
    # Encodes an n-ary tree to a binary tree.
    def encode(self, root: 'Node') -> TreeNode:
        if not root:
            return None
        b_root = TreeNode(root.val)
        if not root.children:
            return b_root
        # encode first child
        b_root.left = self.encode(root.children[0])
        # link siblings via right pointers
        cur = b_root.left
        for child in root.children[1:]:
            cur.right = self.encode(child)
            cur = cur.right
        return b_root

    # Decodes your binary tree to an n-ary tree.
    def decode(self, data: TreeNode) -> 'Node':
        if not data:
            return None
        n_root = Node(data.val, [])
        # first child is left of binary node
        cur = data.left
        while cur:
            n_root.children.append(self.decode(cur))
            cur = cur.right
        return n_root
