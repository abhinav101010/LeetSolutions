class Solution:
    def findContestMatch(self, n: int) -> str:
        teams = [str(i) for i in range(1, n+1)]
        while len(teams) > 1:
            half = len(teams) // 2
            new_teams = []
            for i in range(half):
                new_teams.append("(" + teams[i] + "," + teams[len(teams)-1-i] + ")")
            teams = new_teams
        return teams[0]
