class Activity:
    def __init__(self, machine_id, process_id, activity_type, timestamp):
        self.machine_id = machine_id
        self.process_id = process_id
        self.activity_type = activity_type
        self.timestamp = timestamp

class Solution:
    def processingTime(self, activity):
        start_map = {}
        for a in activity:
            if a.activity_type == 'start':
                key = (a.machine_id, a.process_id)
                start_map[key] = a.timestamp
        durations_by_machine = {}
        for a in activity:
            if a.activity_type == 'end':
                key = (a.machine_id, a.process_id)
                if key in start_map:
                    dur = a.timestamp - start_map[key]
                    durations_by_machine.setdefault(a.machine_id, []).append(dur)
        res = []
        for mid, durs in durations_by_machine.items():
            avg = sum(durs) / len(durs) if durs else 0.0
            avg = round(avg, 3)
            res.append((mid, avg))
        res.sort(key=lambda x: x[0])
        return res
