class Solution:
    def asteroidsDestroyed(self, mass: int, asteroids: List[int]) -> bool:
        asteroids.sort()
        print(asteroids)

        planetMass = mass

        for i in range(len(asteroids)):
            if asteroids[i] <= planetMass:
                planetMass+=asteroids[i]
            else:
                return False
        return True