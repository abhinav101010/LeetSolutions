from typing import List
from dataclasses import dataclass

@dataclass
class Activity:
    player_id: int
    device_id: int
    event_date: str
    games_played: int

class Solution:
    def gamePlayAnalysisII(self, activity: List[Activity]) -> List[List]:
        first = {}
        for a in activity:
            if a.player_id not in first or a.event_date < first[a.player_id].event_date:
                first[a.player_id] = a
        res = [[pid, first[pid].device_id] for pid in first]
        res.sort(key=lambda x: x[0])
        return res
