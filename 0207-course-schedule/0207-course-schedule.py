from collections import deque, defaultdict
from typing import List

class Solution:
    def canFinish(self, numCourses: int, prerequisites: List[List[int]]) -> bool:
        graph = defaultdict(list)
        indegree = [0] * numCourses
        
        for dest, src in prerequisites:
            graph[src].append(dest)
            indegree[dest] += 1
        
        queue = deque([i for i in range(numCourses) if indegree[i] == 0])
        count = 0
        
        while queue:
            course = queue.popleft()
            count += 1
            for nei in graph[course]:
                indegree[nei] -= 1
                if indegree[nei] == 0:
                    queue.append(nei)
        
        return count == numCourses