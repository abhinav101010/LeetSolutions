from collections import deque

class Solution:
    def racecar(self, target: int) -> int:
        # BFS over (position, speed)
        queue = deque()
        queue.append((0, 1))  # position, speed
        visited = set()
        visited.add((0, 1))
        steps = 0
        while queue:
            for _ in range(len(queue)):
                pos, speed = queue.popleft()
                if pos == target:
                    return steps
                # Accelerate
                new_pos = pos + speed
                new_speed = speed * 2
                if (new_pos, new_speed) not in visited:
                    # prune: if new_pos is too far away, maybe skip
                    if 0 <= new_pos <= 2 * target:
                        visited.add((new_pos, new_speed))
                        queue.append((new_pos, new_speed))
                # Reverse
                new_speed2 = -1 if speed > 0 else 1
                if (pos, new_speed2) not in visited:
                    visited.add((pos, new_speed2))
                    queue.append((pos, new_speed2))
            steps += 1
        return -1
