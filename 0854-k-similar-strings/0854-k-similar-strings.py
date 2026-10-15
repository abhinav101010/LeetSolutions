import collections

class Solution:
    def kSimilarity(self, s1: str, s2: str) -> int:
        if s1 == s2:
            return 0
        # BFS
        queue = collections.deque([s1])
        visited = {s1}
        steps = 0
        n = len(s1)
        while queue:
            for _ in range(len(queue)):
                cur = queue.popleft()
                # find first mismatch
                i = 0
                while i < n and cur[i] == s2[i]:
                    i += 1
                # try swapping with any j>i where cur[j]==s2[i] and cur[j]!=s2[j] (to avoid unnecessary)
                lst = list(cur)
                for j in range(i+1, n):
                    if lst[j] == s2[i] and lst[j] != s2[j]:
                        lst[i], lst[j] = lst[j], lst[i]
                        nxt = ''.join(lst)
                        if nxt == s2:
                            return steps + 1
                        if nxt not in visited:
                            visited.add(nxt)
                            queue.append(nxt)
                        # backtrack
                        lst[i], lst[j] = lst[j], lst[i]
            steps += 1
        return steps
