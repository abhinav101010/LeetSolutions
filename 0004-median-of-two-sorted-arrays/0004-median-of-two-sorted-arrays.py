class Solution:
    def findMedianSortedArrays(self, nums1: List[int], nums2: List[int]) -> float:
        numList = nums1+nums2
        numList.sort()
        print(numList)

        n=len(numList)
        print(n)

        if n % 2 != 0:
            return numList[n//2]
        
        if n % 2 == 0:
            return (numList[(n//2) - 1] + numList[(n//2)])/2

        return 0.0