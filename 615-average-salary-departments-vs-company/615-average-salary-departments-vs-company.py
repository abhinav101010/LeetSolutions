class Solution:
    def companies_below_avg(self, employees):
        from collections import defaultdict
        allsal = defaultdict(list)
        for e in employees: allsal[e['company']].append(e['salary'])
        out=[]
        for comp in allsal:
            mgrs = {e['manager_id'] for e in employees if e['company']==comp and e.get('manager_id') is not None}
            mgr_sal = [e['salary'] for e in employees if e['company']==comp and e['id'] in mgrs]
            if not mgr_sal: continue
            comp_avg = sum(allsal[comp])/len(allsal[comp])
            mgr_avg = sum(mgr_sal)/len(mgr_sal)
            if comp_avg < mgr_avg: out.append(comp)
        return out
