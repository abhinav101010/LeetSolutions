class Person:
    def __init__(self, id, email):
        self.id = id
        self.email = email

class Solution:
    def duplicateEmails(self, persons):
        cnt = {}
        for p in persons:
            cnt[p.email] = cnt.get(p.email, 0) + 1
        ans = []
        for e, c in cnt.items():
            if c > 1:
                ans.append([e])
        return ans
