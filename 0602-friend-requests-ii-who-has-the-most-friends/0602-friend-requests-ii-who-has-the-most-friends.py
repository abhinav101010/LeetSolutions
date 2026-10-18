class RequestAccepted:
    def __init__(self, requester_id, accepter_id):
        self.requester_id = requester_id
        self.accepter_id = accepter_id

class Solution:
    def mostFriends(self, requests):
        s = set()
        for r in requests:
            s.add((r.requester_id, r.accepter_id))
        cnt = {}
        for r in requests:
            if (r.accepter_id, r.requester_id) in s:
                cnt[r.requester_id] = cnt.get(r.requester_id, 0) + 1
        bestId = -1
        bestNum = -1
        for id, c in cnt.items():
            if c > bestNum or (c == bestNum and id < bestId):
                bestNum = c
                bestId = id
        ans = []
        if bestId >= 0:
            ans.append([str(bestId), str(bestNum)])
        return ans
