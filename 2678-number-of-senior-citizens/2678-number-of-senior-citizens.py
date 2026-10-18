class Solution:
    def countSeniors(self, details):
        return sum(int(x[11:13]) > 60 for x in details)
