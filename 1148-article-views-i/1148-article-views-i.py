from typing import List
from collections import defaultdict

class View:
    def __init__(self, article_id: int, author_id: int, viewer_id: int, view_date: str):
        self.article_id = article_id
        self.author_id = author_id
        self.viewer_id = viewer_id
        self.view_date = view_date

class Solution:
    def articleViewsI(self, views: List[View]) -> List[int]:
        seen = set()
        for v in views:
            if v.author_id == v.viewer_id:
                seen.add(v.author_id)
        result = sorted(seen)
        return result
