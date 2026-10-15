class Solution:
    def tallestBillboard(self, rods: list[int]) -> int:
        dp = {0: 0}  # diff -> max height of positive side
        for r in rods:
            newdp = dict(dp)
            for diff, h in dp.items():
                # add to positive side
                ndiff = diff + r
                nh = h + r
                if nh > newdp.get(ndiff, 0):
                    newdp[ndiff] = nh
                # add to negative side
                ndiff = diff - r
                nh = h  # positive side unchanged
                if nh > newdp.get(ndiff, 0):
                    newdp[ndiff] = nh
            dp = newdp
        return dp.get(0, 0)
