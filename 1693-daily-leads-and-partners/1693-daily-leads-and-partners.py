from typing import List
from dataclasses import dataclass
from collections import defaultdict

@dataclass
class DailySales:
    date_id: str
    make_name: str
    lead_id: int
    partner_id: int

class Solution:
    def dailyLeadsAndPartners(self, sales: List[DailySales]) -> List[List]:
        leads = defaultdict(set)
        partners = defaultdict(set)
        for s in sales:
            key = (s.date_id, s.make_name)
            leads[key].add(s.lead_id)
            partners[key].add(s.partner_id)
        res = []
        for key in leads:
            res.append([key[0], key[1], len(leads[key]), len(partners[key])])
        res.sort(key=lambda x: (x[0], x[1]))
        return res
