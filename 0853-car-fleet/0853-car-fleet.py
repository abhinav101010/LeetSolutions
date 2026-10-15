class Solution:
    def carFleet(self, target: int, position: list[int], speed: list[int]) -> int:
        pairs = sorted(zip(position, speed), key=lambda x: -x[0])
        times = [(target - p) / s for p, s in pairs]
        fleets = 0
        prev = 0.0
        for t in times:
            if t > prev:
                fleets += 1
                prev = t
        return fleets
