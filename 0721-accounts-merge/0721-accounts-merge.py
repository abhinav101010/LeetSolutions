import collections
from typing import List

class Solution:
    def accountsMerge(self, accounts: List[List[str]]) -> List[List[str]]:
        n = len(accounts)
        parent = list(range(n))
        email_to_id = {}
        email_to_name = {}
        def find(x):
            while parent[x] != x:
                parent[x] = parent[parent[x]]
                x = parent[x]
            return x
        def union(a, b):
            ra, rb = find(a), find(b)
            if ra != rb:
                parent[rb] = ra
        for i, acc in enumerate(accounts):
            name = acc[0]
            for email in acc[1:]:
                email_to_name[email] = name
                if email not in email_to_id:
                    email_to_id[email] = i
                else:
                    union(i, email_to_id[email])
        groups = collections.defaultdict(list)
        for email, idx in email_to_id.items():
            root = find(idx)
            groups[root].append(email)
        res = []
        for emails in groups.values():
            name = email_to_name[emails[0]]
            res.append([name] + sorted(emails))
        return res
