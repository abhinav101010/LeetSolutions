class Solution:
    def nextGreaterElement(self, nums1: List[int], nums2: List[int]) -> List[int]:
        ans = []

        for num in nums1:
            i = nums2.index(num)

            while i < len(nums2):
                if nums2[i] > num:
                    ans.append(nums2[i])
                    break

                i += 1
            else:
                ans.append(-1)
        return ans