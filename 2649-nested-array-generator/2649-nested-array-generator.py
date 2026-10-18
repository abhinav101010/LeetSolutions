# 2649-nested-array-generator

class Solution:
    def inorderTraversal(self, arr):
        # Simple approach - flatten nested array
        result = []
        def dfs(x):
            if isinstance(x, int):
                result.append(x)
            else:
                for item in x:
                    dfs(item)
        dfs(arr)
        return iter(result)
