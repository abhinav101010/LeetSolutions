class Solution:
    def canVisitAllRooms(self, rooms: list[list[int]]) -> bool:
        n = len(rooms)
        visited = [False] * n
        stack = [0]
        visited[0] = True
        while stack:
            room = stack.pop()
            for nxt in rooms[room]:
                if not visited[nxt]:
                    visited[nxt] = True
                    stack.append(nxt)
        return all(visited)
