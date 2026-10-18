class Solution:
    def games_played_so_far(self, activities):
        activities = sorted(activities, key=lambda a:(a['player_id'], a['event_date']))
        running={}
        out=[]
        for a in activities:
            running[a['player_id']]=running.get(a['player_id'],0)+a['games_played']
            out.append([a['player_id'], a['event_date'], running[a['player_id']]])
        return out
