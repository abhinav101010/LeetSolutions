# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

from collections import deque
from typing import List

class Solution:
    def findClosestLeaf(self, root: TreeNode, k: int) -> int:
        # build adjacency list
        graph = {}
        def dfs(node, parent = None):
            if not node:
                return
            if node not in graph:
                graph[node] = []
            if parent:
                graph[node].append(parent)
                graph[parent].append(node)
            dfs(node.left, node)
            dfs(node.right, node)
        dfs(root)
        # find target node
        target = None
        for node in graph:
            if node.val == k:
                target = node
                break
        if not target:
            return -1  # should not happen per problem
        # BFS from target to find nearest leaf
        q = deque([target])
        visited = set([target])
        while q:
            node = q.popleft()
            # check if leaf: degree 1 (except root could be leaf with degree 0)
            # In graph representation, leaf node will have only one neighbor (its parent) unless it's root with no children.
            # In our graph, root will have degree equal to number of children (0,1,2). So leaf condition: len(graph[node]) == 1 or (len(graph[node]) == 0 and node has no children) but we don't have children info.
            # Simpler: leaf in original tree means node.left == null and node.right == null.
            if not node.left and not node.right:
                return node.val
            for nei in graph[node]:
                if nei not in visited:
                    visited.add(nei)
                    q.append(nei)
        return -1  # should not happen
