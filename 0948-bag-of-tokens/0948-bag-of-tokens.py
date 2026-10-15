class Solution:
    def bagOfTokensScore(self, tokens: list[int], P: int) -> int:
        tokens.sort()
        i, j = 0, len(tokens)-1
        score = 0
        max_score = 0
        while i <= j:
            if P >= tokens[i]:
                P -= tokens[i]
                score += 1
                i += 1
                max_score = max(max_score, score)
            elif score > 0:
                P += tokens[j]
                score -= 1
                j -= 1
            else:
                break
        return max_score
