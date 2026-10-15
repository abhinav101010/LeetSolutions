# Definition for a binary tree node.
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution:
    def distanceK(self, root: TreeNode, target: TreeNode, k: int) -> list[int]:
        parent = {}
        def dfs(node, par):
            if node:
                parent[node] = par
                dfs(node.left, node)
                dfs(node.right, node)
        dfs(root, None)
        from collections import deque
        q = deque([target])
        visited = {target}
        dist = 0
        while q and dist < k:
            for _ in range(len(q)):
                node = q.popleft()
                for nei in (node.left, node.right, parent.get(node)):
                    if nei and nei not in visited:
                        visited.add(nei)
                        q.append(nei)
            dist += 1
        return [node.val for node in q]
