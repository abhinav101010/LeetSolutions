class Solution:
    def hIndex(self, citations: List[int]) -> int:
        # citations.sort()
        # n = len(citations)
        # for i in range(n):
        #     h = n - i
        #     if citations[i] >= h:
        #         return h
        # return 0


        n = len(citations)
        left = 0
        right = n - 1

        while left <= right:
            mid = (left + right) // 2

            if citations[mid] >= n - mid:
                right = mid - 1
            else:
                left = mid + 1

        return n - left