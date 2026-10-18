class Candidate:
    def __init__(self, id, name, vote):
        self.id = id
        self.name = name
        self.vote = vote

class Solution:
    def winningCandidate(self, candidates):
        if not candidates:
            return ""
        maxVote = max(c.vote for c in candidates)
        for c in candidates:
            if c.vote == maxVote:
                return c.name
        return ""
