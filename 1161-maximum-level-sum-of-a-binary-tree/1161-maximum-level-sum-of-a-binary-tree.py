class Solution:
    def maxLevelSum(self, root) -> int:
        level_sum = []

        def dfs(node, level):
            if not node:
                return
            if level == len(level_sum):
                level_sum.append(node.val)
            else:
                level_sum[level] += node.val
            dfs(node.left, level + 1)
            dfs(node.right, level + 1)

        dfs(root, 0)
        ans = 0
        for i in range(len(level_sum)):
            if level_sum[i] > level_sum[ans]:
                ans = i
        return ans + 1