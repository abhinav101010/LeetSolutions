class Solution:
    def primary_dept(self, employees):
        from collections import Counter
        cnt = Counter(e['employee_id'] for e in employees)
        seen=set(); out=[]
        for e in employees:
            if e['primary_flag']=='Y' or cnt[e['employee_id']]==1:
                k=(e['employee_id'],e['department_id'])
                if k not in seen:
                    seen.add(k); out.append(list(k))
        return out
