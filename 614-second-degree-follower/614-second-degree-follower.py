from typing import List


class Follow:
    def __init__(self, follower: int, followee: int):
        self.follower = follower
        self.followee = followee


class Solution:
    def secondDegreeFollower(self, follow: List[Follow]) -> List[List[str]]:
        resultSet = set()
        for f1 in follow:
            for f2 in follow:
                if f1.followee == f2.follower:
                    resultSet.add(f2.followee)
        return [[str(x)] for x in sorted(resultSet)]
