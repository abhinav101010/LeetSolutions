class Solution:
    def videoStitching(self, clips, T):
        clips.sort()
        res = 0
        curr_end = next_end = 0
        i = 0
        n = len(clips)
        while curr_end < T:
            while i < n and clips[i][0] <= curr_end:
                next_end = max(next_end, clips[i][1])
                i += 1
            if next_end == curr_end:
                return -1
            curr_end = next_end
            res += 1
        return res
