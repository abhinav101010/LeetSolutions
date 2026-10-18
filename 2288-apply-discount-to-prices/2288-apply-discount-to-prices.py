class Solution:
    def discountPrices(self, sentence, discount) :
        ans = []
        for w in sentence.split():
            if w[0] == '$' and w[1:].isdigit():
                w = f'${int(w[1:]) * (1 - discount / 100):.2f}'
            ans.append(w)
        return ' '.join(ans)
