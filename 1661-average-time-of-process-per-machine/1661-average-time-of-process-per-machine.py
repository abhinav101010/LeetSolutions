class Solution:
    def avg_time(self, activities):
        m = {}
        for a in activities:
            key = (a['machine_id'], a['process_id'])
            m.setdefault(key, {})[a['activity_type']] = a['timestamp']
        bym = {}
        for (mid,pid),v in m.items():
            bym.setdefault(mid, []).append(v['end']-v['start'])
        return {mid: sum(ds)/len(ds) for mid,ds in bym.items()}
