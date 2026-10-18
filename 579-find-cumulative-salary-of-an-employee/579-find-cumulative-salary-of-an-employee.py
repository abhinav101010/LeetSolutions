class Solution:
    def cumulative_salary(self, employees):
        from collections import defaultdict
        byid = defaultdict(dict)
        for e in employees:
            byid[e['id']][e['month']] = e['salary']
        out=[]
        for eid, months in byid.items():
            ms = sorted(months)
            maxm = max(ms)
            for m in ms:
                if m == maxm: continue
                s = sum(months[mm] for mm in ms if mm<=m and mm>=m-2)
                out.append([eid,m,s])
        return out
