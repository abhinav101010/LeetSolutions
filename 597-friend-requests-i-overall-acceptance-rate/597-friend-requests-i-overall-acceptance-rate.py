from typing import List
from dataclasses import dataclass

@dataclass
class FriendRequest:
    sender_id: int
    send_to_id: int
    request_date: str

@dataclass
class RequestAccepted:
    requester_id: int
    accepter_id: int
    accept_date: str

class Solution:
    def acceptanceRate(self, requests: List[FriendRequest], accepted: List[RequestAccepted]) -> str:
        req_set = set((r.sender_id, r.send_to_id) for r in requests)
        acc_set = set((a.requester_id, a.accepter_id) for a in accepted)
        if not req_set:
            return "0.00"
        total_acc = sum(1 for a in acc_set if a in req_set)
        rate = total_acc / len(req_set)
        # round to 2 decimals
        return "{:.2f}".format(round(rate, 2))
