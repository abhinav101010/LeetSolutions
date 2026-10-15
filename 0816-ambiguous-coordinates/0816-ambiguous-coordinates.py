class Solution:
    def ambiguousCoordinates(self, s: str) -> list[str]:
        # remove parentheses
        inner = s[1:-1]
        def make_frag(frag):
            n = len(frag)
            res = []
            if n == 0:
                return res
            # no decimal
            if not (frag[0] == '0' and n > 1):
                res.append(frag)
            # with decimal
            for i in range(1, n):
                left = frag[:i]
                right = frag[i:]
                if (left[0] == '0' and len(left) > 1):
                    continue
                if right[-1] == '0':
                    continue
                res.append(left + '.' + right)
            return res
        ans = []
        for i in range(1, len(inner)):
            left = inner[:i]
            right = inner[i:]
            left_opts = make_frag(left)
            right_opts = make_frag(right)
            for l in left_opts:
                for r in right_opts:
                    ans.append(f'({l}, {r})')
        return ans
