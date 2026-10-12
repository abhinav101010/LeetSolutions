# Definition for a Node.
class Node:
    def __init__(self, val = 0, neighbors = None):
        self.val = val
        self.neighbors = neighbors if neighbors is not None else []

from collections import deque

class Solution:
    def cloneGraph(self, node: 'Node') -> 'Node':
        if not node:
            return None
        
        visited = {}
        
        def dfs(original: 'Node') -> 'Node':
            if original in visited:
                return visited[original]
            
            clone = Node(original.val)
            visited[original] = clone
            
            for neighbor in original.neighbors:
                clone.neighbors.append(dfs(neighbor))
            
            return clone
        
        return dfs(node)