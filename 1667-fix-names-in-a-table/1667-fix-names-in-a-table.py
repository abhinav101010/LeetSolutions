class User:
    def __init__(self, user_id, name):
        self.user_id = user_id
        self.name = name

class Solution:
    def fixNames(self, users):
        res = []
        for u in users:
            fixed = u.name[0].upper() + u.name[1:].lower() if u.name else u.name
            res.append((u.user_id, fixed))
        res.sort(key=lambda x: x[0])
        return res
