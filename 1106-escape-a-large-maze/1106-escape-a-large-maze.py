from collections import deque
class Solution:
    def isEscapePossible(self, blocked, source, target):
        if not blocked:
            return True
        blocked_set = set((x, y) for x, y in blocked)
        limit = len(blocked) * (len(blocked) - 1) // 2
        def bfs(start, end):
            q = deque([tuple(start)])
            seen = {tuple(start)}
            while q and len(seen) <= limit:
                x, y = q.popleft()
                if [x, y] == end:
                    return True
                for dx, dy in ((1,0),(-1,0),(0,1),(0,-1)):
                    nx, ny = x + dx, y + dy
                    if 0 <= nx < 10**6 and 0 <= ny < 10**6 and (nx, ny) not in blocked_set and (nx, ny) not in seen:
                        seen.add((nx, ny))
                        q.append((nx, ny))
            return len(seen) > limit
        return bfs(source, target) and bfs(target, source)
