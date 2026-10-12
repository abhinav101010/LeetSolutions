from collections import defaultdict, deque
from typing import List

class Solution:
    def findLadders(self, beginWord: str, endWord: str, wordList: List[str]) -> List[List[str]]:
        wordSet = set(wordList)
        if endWord not in wordSet:
            return []
        
        # Build adjacency graph
        graph = defaultdict(list)
        for word in wordSet:
            for i in range(len(word)):
                pattern = word[:i] + '*' + word[i+1:]
                graph[pattern].append(word)
        
        # BFS to find shortest paths
        level = {beginWord: [[beginWord]]}
        visited = set([beginWord])
        found = False
        
        while level and not found:
            next_level = defaultdict(list)
            for word, paths in level.items():
                if word == endWord:
                    found = True
                    return paths
                
                for i in range(len(word)):
                    pattern = word[:i] + '*' + word[i+1:]
                    for nei in graph[pattern]:
                        if nei not in visited:
                            for path in paths:
                                next_level[nei].append(path + [nei])
            
            visited.update(next_level.keys())
            level = next_level
        
        return []