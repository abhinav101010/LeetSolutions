class Solution:
    def expressiveWords(self, s: str, words: list[str]) -> int:
        def count_groups(st):
            groups = []
            i = 0
            while i < len(st):
                j = i
                while j < len(st) and st[j] == st[i]:
                    j += 1
                groups.append((st[i], j - i))
                i = j
            return groups
        s_groups = count_groups(s)
        ans = 0
        for w in words:
            w_groups = count_groups(w)
            if len(w_groups) != len(s_groups):
                continue
            ok = True
            for (c1, l1), (c2, l2) in zip(w_groups, s_groups):
                if c1 != c2:
                    ok = False
                    break
                if l1 > l2:
                    ok = False
                    break
                if l1 < l2 and l2 < 3:
                    ok = False
                    break
            if ok:
                ans += 1
        return ans
