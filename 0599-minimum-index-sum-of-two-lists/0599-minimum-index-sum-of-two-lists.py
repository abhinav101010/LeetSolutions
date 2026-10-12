class Solution:
    def findRestaurant(self, list1: List[str], list2: List[str]) -> List[str]:
        ans = []
        leastIndex = float("inf")
        for i in range(len(list1)):
            if list1[i] in list2:
                idx = list2.index(list1[i]) + i
                if idx < leastIndex:
                    leastIndex = idx
                    ans = [list1[i]]
                elif idx == leastIndex:
                    ans.append(list1[i])
        return ans