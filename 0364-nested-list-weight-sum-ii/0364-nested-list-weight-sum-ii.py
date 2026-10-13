class Solution:
    def depthSumInverse(self, nestedList: List[NestedInteger]) -> int:
        def get_max_depth(nl):
            res = 1
            for ni in nl:
                if not ni.isInteger():
                    res = max(res, 1 + get_max_depth(ni.getList()))
            return res
        
        def dfs(nl, depth):
            res = 0
            for ni in nl:
                if ni.isInteger():
                    res += ni.getInteger() * depth
                else:
                    res += dfs(ni.getList(), depth - 1)
            return res
        
        max_d = get_max_depth(nestedList)
        return dfs(nestedList, max_d)