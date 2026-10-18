# Definition for a Node.
class Node:
    def __init__(self, val=None, children=None):
        self.val = val
        self.children = children if children is not None else []

class Codec:
    def serialize(self, root: 'Node') -> str:
        def dfs(node):
            if not node:
                return []
            res = [str(node.val), str(len(node.children))]
            for child in node.children:
                res.extend(dfs(child))
            return res
        return ','.join(dfs(root))
    
    def deserialize(self, data: str) -> 'Node':
        if not data:
            return None
        tokens = iter(data.split(','))
        def dfs():
            val = int(next(tokens))
            size = int(next(tokens))
            node = Node(val, [])
            for _ in range(size):
                node.children.append(dfs())
            return node
        return dfs()
