from typing import List


class Tree:
    def __init__(self, id: int, p_id):
        self.id = id
        self.p_id = p_id


class Solution:
    def treeNode(self, tree: List[Tree]) -> List[List[str]]:
        isParent = set()
        for t in tree:
            if t.p_id is not None:
                isParent.add(t.p_id)
        result = []
        for t in sorted(tree, key=lambda x: x.id):
            if t.p_id is None:
                typ = "Root"
            elif t.id in isParent:
                typ = "Inner"
            else:
                typ = "Leaf"
            result.append([str(t.id), typ])
        return result
