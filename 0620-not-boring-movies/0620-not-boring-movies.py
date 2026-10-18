from typing import List

class Cinema:
    def __init__(self, id: int, movie: str, description: str, rating: float):
        self.id = id
        self.movie = movie
        self.description = description
        self.rating = rating

class Solution:
    def notBoringMovies(self, cinema: List[Cinema]) -> List[Cinema]:
        result = []
        for c in cinema:
            if c.id % 2 == 1 and c.description != 'boring':
                result.append(c)
        result.sort(key=lambda x: (-x.rating, x.id))
        return result
