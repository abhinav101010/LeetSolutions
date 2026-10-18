from typing import List
from collections import defaultdict

class Login:
    def __init__(self, user_id: int, time_stamp: str):
        self.user_id = user_id
        self.time_stamp = time_stamp

class Result:
    def __init__(self, user_id: int, last_stamp: str):
        self.user_id = user_id
        self.last_stamp = last_stamp

class Solution:
    def latestLogin(self, logins: List[Login]) -> List[Result]:
        user_latest = {}
        for l in logins:
            if l.time_stamp.startswith('2020'):
                if l.user_id not in user_latest or l.time_stamp > user_latest[l.user_id]:
                    user_latest[l.user_id] = l.time_stamp
        # Return in any order - but we can sort by user_id for consistency
        result = []
        for user_id in sorted(user_latest.keys()):
            result.append(Result(user_id, user_latest[user_id]))
        return result
