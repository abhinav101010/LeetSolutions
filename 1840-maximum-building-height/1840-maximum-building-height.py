class Solution:
    def maxBuilding(self, n: int, restrictions: List[List[int]]) -> int:
        # buildingRestrictions = {
        #     **{i: 5 for i in range(1, n + 1)},
        #     **dict(restrictions),
        #     0: 0,
        # }
        # print(buildingRestrictions)

        # ans = {0:0}
        # for i in range(0,n):
        #     if i > 0:
        #         height = min(buildingRestrictions[i-1], buildingRestrictions[i+1]) + 1
        #         if height <= buildingRestrictions[i]:
        #             ans.update({i:height})
        # print(ans)
        # return max(ans.values())

        # buildingRestrictions = {
        #     **dict(restrictions),
        #     1: 0,
        # }

        # ans = {}
        # height = 0
        # for i in range(1, n+1):
        #     if i in buildingRestrictions.keys() and height > buildingRestrictions[i]:
        #         height = buildingRestrictions[i]
        #         ans.update({i:height})

        #         if abs(ans[i]-ans[i-1])>1:
        #             if (ans[i]-ans[i-1]) > 1:
        #                 ans[i] = ans[i-1]+1
        #             elif (ans[i]-ans[i-1]) < -1:
        #                 ans[i-1] = ans[i]+1
        #     else:
        #         ans.update({i:height})
        #     height+=1

        # changed = True
        # while changed:
        #     changed = False

        #     for i in range(2, n + 1):
        #         if ans[i] > ans[i - 1] + 1:
        #             ans[i] = ans[i - 1] + 1
        #             changed = True

        #         elif ans[i - 1] > ans[i] + 1:
        #             ans[i - 1] = ans[i] + 1
        #             changed = True

        # print(ans)
        # return max(ans.values())

        restrictions.append([1, 0])

        if restrictions[-1][0] != n:
            restrictions.append([n, n - 1])

        restrictions.sort()

        # Left -> Right
        for i in range(1, len(restrictions)):
            dist = restrictions[i][0] - restrictions[i - 1][0]
            restrictions[i][1] = min(
                restrictions[i][1],
                restrictions[i - 1][1] + dist
            )

        # Right -> Left
        for i in range(len(restrictions) - 2, -1, -1):
            dist = restrictions[i + 1][0] - restrictions[i][0]
            restrictions[i][1] = min(
                restrictions[i][1],
                restrictions[i + 1][1] + dist
            )

        ans = 0

        # Maximum peak between consecutive restricted buildings
        for i in range(1, len(restrictions)):
            x1, h1 = restrictions[i - 1]
            x2, h2 = restrictions[i]

            dist = x2 - x1
            peak = (h1 + h2 + dist) // 2

            ans = max(ans, peak)

        return ans