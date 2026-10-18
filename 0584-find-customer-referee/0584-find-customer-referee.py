from typing import List, Optional


class Customer:
    def __init__(self, id: int, name: str, referee_id: Optional[int]):
        self.id = id
        self.name = name
        self.referee_id = referee_id


class Solution:
    def findCustomerReferee(self, customers: List[Customer]) -> List[str]:
        return [c.name for c in customers if c.referee_id is None or c.referee_id != 2]
