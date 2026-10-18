class Follower:
    def __init__(self, user_id, follower_id):
        self.user_id = user_id
        self.follower_id = follower_id

class Solution:
    def findFollowersCount(self, followers):
        cnt = {}
        for f in followers:
            cnt[f.user_id] = cnt.get(f.user_id, 0) + 1
        ans = []
        for u, c in cnt.items():
            ans.append([str(u), str(c)])
        ans.sort(key=lambda r: int(r[0]))
        return ans
