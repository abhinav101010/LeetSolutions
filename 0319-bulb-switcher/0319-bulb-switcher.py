class Solution:
    def bulbSwitch(self, n: int) -> int:
        # The bulbs that are on are those with an odd number of factors
        # Only perfect squares have an odd number of factors
        return int(n ** 0.5)