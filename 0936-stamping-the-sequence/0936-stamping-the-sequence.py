class Solution:
    def movesToStamp(self, stamp: str, target: str) -> list[int]:
        s_len = len(stamp)
        t_len = len(target)
        target_list = list(target)
        visited = [False]*t_len
        res = []
        def check(i):
            nonlocal target_list
            changed = False
            for j in range(s_len):
                if target_list[i+j] == '*':
                    continue
                if target_list[i+j] != stamp[j]:
                    return False
                changed = True
            if changed:
                for j in range(s_len):
                    target_list[i+j] = '*'
                res.append(i)
                return True
            return False
        changed = True
        while changed:
            changed = False
            for i in range(t_len - s_len + 1):
                if not visited[i] and check(i):
                    visited[i] = True
                    changed = True
        if all(c == '*' for c in target_list):
            res.reverse()
            return res
        else:
            return []
