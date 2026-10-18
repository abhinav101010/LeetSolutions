class AuthenticationManager:
    def __init__(self, timeToLive):
        self.t = timeToLive
        self.d = defaultdict(int)

    def generate(self, tokenId, currentTime):
        self.d[tokenId] = currentTime + self.t

    def renew(self, tokenId, currentTime):
        if self.d[tokenId] <= currentTime:
            return
        self.d[tokenId] = currentTime + self.t

    def countUnexpiredTokens(self, currentTime):
        return sum(exp > currentTime for exp in self.d.values())


# Your AuthenticationManager object will be instantiated and called as such:
# obj = AuthenticationManager(timeToLive)
# obj.generate(tokenId,currentTime)
# obj.renew(tokenId,currentTime)
# param_3 = obj.countUnexpiredTokens(currentTime)
