from collections import defaultdict

class User:
    def __init__(self, id, name):
        self.id = id
        self.name = name

class Ride:
    def __init__(self, id, user_id, distance):
        self.id = id
        self.user_id = user_id
        self.distance = distance

class Solution:
    def topTravellers(self, users, rides):
        dist = defaultdict(int)
        for r in rides:
            dist[r.user_id] += r.distance
        res = []
        for u in users:
            res.append((u.name, dist[u.id]))
        res.sort(key=lambda x: (-x[1], x[0]))
        return res
