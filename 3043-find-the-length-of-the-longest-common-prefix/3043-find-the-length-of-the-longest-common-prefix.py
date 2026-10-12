class Solution:
    def longestCommonPrefix(self, arr1: List[int], arr2: List[int]) -> int:
        # ans = 0

        # for i in range(len(arr1)):
        #     for j in range(len(arr2)):
        #         prefixLenght = 0
        #         for c1, c2 in zip(str(arr1[i]), str(arr2[j])):
        #             if c1 == c2:
        #                 prefixLenght += 1
        #             else:
        #                 break
        #         ans = max(ans, prefixLenght)
        # return ans


        prefixes = set()
        # Store every prefix from arr1
        for num in arr1:
            s = str(num)
            for i in range(1, len(s)+1):
                prefixes.add(s[:i])
                
        ans = 0
        # Check prefixes of arr2
        for num in arr2:
            s = str(num)
            for i in range(1, len(s)+1):
                if s[:i] in prefixes:
                    ans = max(ans, i)
        return ans