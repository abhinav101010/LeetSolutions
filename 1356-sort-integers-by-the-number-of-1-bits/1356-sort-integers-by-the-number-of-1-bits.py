class Solution:
    def sortByBits(self, arr: List[int]) -> List[int]:
        nextBitCount = 0
        ans = []

        while arr:
            unsortedAnsArr = []
            remaining = []

            for num in arr:
                bitsCount = bin(num).count("1")  # or num.bit_count()

                if bitsCount == nextBitCount:
                    unsortedAnsArr.append(num)
                else:
                    remaining.append(num)

            ans.extend(sorted(unsortedAnsArr))
            arr = remaining
            nextBitCount += 1
        return ans