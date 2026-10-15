class Solution:
    def numBusesToDestination(self, routes: list[list[int]], source: int, target: int) -> int:
        if source == target:
            return 0
        # map stop -> list of route indices
        stop_to_routes = {}
        for i, route in enumerate(routes):
            for stop in route:
                stop_to_routes.setdefault(stop, []).append(i)
        # BFS over routes
        from collections import deque
        visited_routes = set()
        q = deque()
        for rt in stop_to_routes.get(source, []):
            q.append((rt, 1))  # (route index, buses taken)
            visited_routes.add(rt)
        target_set = set(stop_to_routes.get(target, []))
        while q:
            rt, buses = q.popleft()
            if rt in target_set:
                return buses
            for stop in routes[rt]:
                for nxt_rt in stop_to_routes[stop]:
                    if nxt_rt not in visited_routes:
                        visited_routes.add(nxt_rt)
                        q.append((nxt_rt, buses + 1))
        return -1
