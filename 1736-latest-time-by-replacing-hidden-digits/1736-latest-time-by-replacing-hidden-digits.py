class Solution:
    def maximumTime(self, time: str) -> str:
        time = list(time)

        # Hour tens
        if time[0] == '?':
            if time[1] == '?' or time[1] <= '3':
                time[0] = '2'
            else:
                time[0] = '1'

        # Hour ones
        if time[1] == '?':
            if time[0] == '2':
                time[1] = '3'
            else:
                time[1] = '9'

        # Minute tens
        if time[3] == '?':
            time[3] = '5'

        # Minute ones
        if time[4] == '?':
            time[4] = '9'

        return ''.join(time)