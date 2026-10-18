from typing import List


class User:
    def __init__(self, user_id: int, user_name: str):
        self.user_id = user_id
        self.user_name = user_name


class Register:
    def __init__(self, contest_id: int, user_id: int):
        self.contest_id = contest_id
        self.user_id = user_id


class Solution:
    def percentageAttended(self, users: List[User], reg: List[Register]) -> List[List[str]]:
        total = len(users)
        cnt = {}
        for r in reg:
            cnt[r.contest_id] = cnt.get(r.contest_id, 0) + 1
        rows = []
        for cid, c in cnt.items():
            if total == 0:
                continue
            rows.append((cid, c * 100.0 / total))
        rows.sort(key=lambda x: (-x[1], x[0]))
        result = []
        for cid, pct in rows:
            result.append([str(cid), f"{pct:.2f}"])
        return result
