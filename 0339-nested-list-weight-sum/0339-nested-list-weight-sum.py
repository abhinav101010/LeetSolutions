class Solution:
    def depthSum(self, nestedList: List[NestedInteger]) -> int:
        res = 0
        
        def dfs(nl, depth):
            nonlocal res
            for ni in nl:
                if ni.isInteger():
                    res += ni.getInteger() * depth
                else:
                    dfs(ni.getList(), depth + 1)
        
        dfs(nestedList, 1)
        return res