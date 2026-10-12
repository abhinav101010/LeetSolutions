from collections import defaultdict
from typing import List

class Solution:
    def findItinerary(self, tickets: List[List[str]]) -> List[str]:
        graph = defaultdict(list)
        for src, dst in tickets:
            graph[src].append(dst)
        
        for src in graph:
            graph[src].sort(reverse=True)
        
        route = []
        
        def dfs(airport):
            while graph[airport]:
                dfs(graph[airport].pop())
            route.append(airport)
        
        dfs("JFK")
        return route[::-1]