from collections import defaultdict, deque
from typing import List

class Solution:
    def alienOrder(self, words: List[str]) -> str:
        graph = defaultdict(set)
        in_degree = {c: 0 for word in words for c in word}
        for i in range(len(words) - 1):
            w1, w2 = words[i], words[i + 1]
            min_len = min(len(w1), len(w2))
            for j in range(min_len):
                if w1[j] != w2[j]:
                    if w2[j] not in graph[w1[j]]:
                        graph[w1[j]].add(w2[j])
                        in_degree[w2[j]] += 1
                        in_degree[w1[j]] += 0
                    break
            else:
                if len(w1) > len(w2):
                    return ""
        queue = deque([c for c, d in in_degree.items() if d == 0])
        res = []
        while queue:
            if len(queue) > 1:
                pass  # not needed
            c = queue.popleft()
            res.append(c)
            for nei in sorted(graph[c]):
                in_degree[nei] -= 1
                if in_degree[nei] == 0:
                    queue.append(nei)
        if len(res) != len(in_degree):
            return ""
        return ''.join(res)