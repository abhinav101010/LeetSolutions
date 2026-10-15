class Solution:
    def robotSim(self, commands: list[int], obstacles: list[list[int]]) -> int:
        obs = set()
        for x, y in obstacles:
            obs.add((x, y))
        # direction: 0=north,1=east,2=south,3=west
        dx = [0, 1, 0, -1]
        dy = [1, 0, -1, 0]
        x = y = 0
        di = 0  # facing north
        ans = 0
        for cmd in commands:
            if cmd == -2:  # left
                di = (di + 3) % 4
            elif cmd == -1:  # right
                di = (di + 1) % 4
            else:
                for _ in range(cmd):
                    nx = x + dx[di]
                    ny = y + dy[di]
                    if (nx, ny) in obs:
                        break
                    x, y = nx, ny
                    ans = max(ans, x*x + y*y)
        return ans
