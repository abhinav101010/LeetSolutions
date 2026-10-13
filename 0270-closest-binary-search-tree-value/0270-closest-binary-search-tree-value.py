class Solution:
    def closestValue(self, root: Optional[TreeNode], target: float) -> int:
        res = root.val
        cur = root
        while cur:
            if abs(cur.val - target) < abs(res - target):
                res = cur.val
            if target < cur.val:
                cur = cur.left
            else:
                cur = cur.right
        return res