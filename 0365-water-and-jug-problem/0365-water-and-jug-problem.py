class Solution:
    def canMeasureWater(self, x: int, y: int, target: int) -> bool:
# Self thought idea
        if target > x + y:
            return False

        seen = set()
        def dfs(a, b):
            if a + b == target: return True
            if (a, b) in seen: return False

            seen.add((a, b))

            # Fill jug1
            if dfs(x, b):
                return True

            # Fill jug2
            if dfs(a, y):
                return True

            # Empty jug1
            if dfs(0, b):
                return True

            # Empty jug2
            if dfs(a, 0):
                return True

            # Pour jug1 -> jug2
            amount = min(a, y - b)

            if dfs(a - amount, b + amount):
                return True

            # Pour jug2 -> jug1
            amount = min(b, x - a)

            if dfs(a + amount, b - amount):
                return True

            return False

        return dfs(0, 0)