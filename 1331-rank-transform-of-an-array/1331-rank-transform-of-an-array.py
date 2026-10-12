class Solution:
    def arrayRankTransform(self, arr: List[int]) -> List[int]:
        # ans = [1 for _ in arr]
        # for i in range(len(arr)):
        #     smaller = set()
        #     for j in range(len(arr)):
        #         if arr[i] > arr[j]:
        #             smaller.add(arr[j])

        #     ans[i] = len(smaller) + 1
        # return 


        ogArr = arr[:]
        arr.sort()
        ranks = {}
        rank = 1

        for num in arr:
            if num not in ranks:
                ranks[num] = rank
                rank += 1

        ans = []
        for num in ogArr:
            ans.append(ranks[num])
        return ans

        









