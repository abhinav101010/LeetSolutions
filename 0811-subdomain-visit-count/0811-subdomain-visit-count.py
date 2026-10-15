class Solution:
    def subdomainVisits(self, cpdomains: list[str]) -> list[str]:
        from collections import Counter
        cnt = Counter()
        for cp in cpdomains:
            count_str, domain = cp.split()
            count = int(count_str)
            parts = domain.split('.')
            for i in range(len(parts)):
                sub = '.'.join(parts[i:])
                cnt[sub] += count
        return [f"{c} {d}" for d, c in cnt.items()]
