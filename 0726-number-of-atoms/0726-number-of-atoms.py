from collections import defaultdict

class Solution:
    def countOfAtoms(self, formula: str) -> str:
        n = len(formula)
        i = 0
        def parse() -> defaultdict:
            nonlocal i
            cnt = defaultdict(int)
            while i < n and formula[i] != ')':
                if formula[i] == '(':
                    i += 1
                    inner = parse()
                    # get multiplier after ')'
                    start = i
                    while i < n and formula[i].isdigit():
                        i += 1
                    mult = int(formula[start:i]) if start != i else 1
                    for ch, v in inner.items():
                        cnt[ch] += v * mult
                else:
                    # parse element name
                    start = i
                    i += 1  # capital letter
                    while i < n and formula[i].islower():
                        i += 1
                    name = formula[start:i]
                    # parse number
                    start_num = i
                    while i < n and formula[i].isdigit():
                        i += 1
                    num = int(formula[start_num:i]) if start_num != i else 1
                    cnt[name] += num
            # now either at end or at ')'
            if i < n and formula[i] == ')':
                i += 1  # skip ')'
            return cnt
        
        final = parse()
        # sort keys
        sorted_items = sorted(final.items())
        res = []
        for name, v in sorted_items:
            res.append(name)
            if v > 1:
                res.append(str(v))
        return ''.join(res)
