class Solution:
    def bagOfTokensScore(self, tokens, P):
        tokens.sort()
        l, r = 0, len(tokens)-1
        score = 0
        max_score = 0
        while l <= r:
            if P >= tokens[l]:
                P -= tokens[l]
                l += 1
                score += 1
                max_score = max(max_score, score)
            elif score > 0:
                P += tokens[r]
                r -= 1
                score -= 1
            else:
                break
        return max_score
