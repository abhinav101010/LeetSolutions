from typing import List
from dataclasses import dataclass
import re

@dataclass
class User:
    user_id: int
    name: str
    mail: str

class Solution:
    def findUsers(self, users: List[User]) -> List[User]:
        res = []
        pattern = re.compile(r'^[A-Za-z][A-Za-z0-9_.-]*@leetcode\.com$')
        for u in users:
            if pattern.match(u.mail):
                res.append(u)
        return res
