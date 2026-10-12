class Solution:
    def largestAltitude(self, gain: List[int]) -> int:
        maxAlt = 0
        alt = 0

        for g in gain:
            alt += g
            maxAlt = max(maxAlt, alt)

        return maxAlt