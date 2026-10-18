from typing import List


class Activity:
    def __init__(self, player_id: int, device_id: int, event_date: str, games_played: int):
        self.player_id = player_id
        self.device_id = device_id
        self.event_date = event_date
        self.games_played = games_played


class Solution:
    def gameAnalysis(self, activity: List[Activity]) -> List[List[str]]:
        first = {}
        for a in activity:
            if a.player_id not in first or a.event_date < first[a.player_id]:
                first[a.player_id] = a.event_date
        return [[str(pid), date] for pid, date in sorted(first.items())]
