from typing import List
from collections import defaultdict

class FriendRequest:
    def __init__(self, senderId: int, sendToId: int):
        self.senderId = senderId
        self.sendToId = sendToId

class RequestAccepted:
    def __init__(self, requesterId: int, accepterId: int):
        self.requesterId = requesterId
        self.accepterId = accepterId

class Solution:
    def friendRequests(self, n: int, requests: List[FriendRequest], accepts: List[RequestAccepted]) -> float:
        request_set = set()
        for r in requests:
            request_set.add((r.senderId, r.sendToId))
        accept_set = set()
        for a in accepts:
            accept_set.add((a.requesterId, a.accepterId))
        if not request_set:
            return 0.0
        accepted_count = 0
        for req in request_set:
            if req in accept_set:
                accepted_count += 1
        return accepted_count / len(request_set)
