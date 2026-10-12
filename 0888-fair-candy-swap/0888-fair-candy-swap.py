class Solution:
    def fairCandySwap(self, aliceSizes: List[int], bobSizes: List[int]) -> List[int]:
        aliceSum = sum(aliceSizes)
        bobSum = sum(bobSizes)

        difference = (bobSum - aliceSum) // 2

        bobSet = set(bobSizes)

        for a in aliceSizes:
            b = a + difference

            if b in bobSet:
                return [a, b]