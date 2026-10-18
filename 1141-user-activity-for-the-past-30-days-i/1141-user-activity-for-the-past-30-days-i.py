from collections import defaultdict

class Activity:
    def __init__(self, user_id, session_id, activity_date, activity_type):
        self.user_id = user_id
        self.session_id = session_id
        self.activity_date = activity_date
        self.activity_type = activity_type

class Solution:
    def userActivity(self, activity):
        day_users = defaultdict(set)
        for a in activity:
            if "2019-06-28" <= a.activity_date <= "2019-07-27":
                day_users[a.activity_date].add(a.user_id)
        res = []
        for d in sorted(day_users.keys()):
            res.append((d, len(day_users[d])))
        return res
