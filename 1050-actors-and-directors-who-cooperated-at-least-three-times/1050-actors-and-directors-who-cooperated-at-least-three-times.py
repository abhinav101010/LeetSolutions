from typing import List


class ActorDirector:
    def __init__(self, actor_id: int, director_id: int, timestamp: int):
        self.actor_id = actor_id
        self.director_id = director_id
        self.timestamp = timestamp


class Solution:
    def actorsAndDirectors(self, actorDirector: List[ActorDirector]) -> List[List[int]]:
        cnt = {}
        for a in actorDirector:
            key = (a.actor_id, a.director_id)
            cnt[key] = cnt.get(key, 0) + 1
        return [[k[0], k[1]] for k, v in cnt.items() if v >= 3]
