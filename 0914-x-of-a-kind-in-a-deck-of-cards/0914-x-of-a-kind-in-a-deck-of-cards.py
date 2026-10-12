class Solution:
    def hasGroupsSizeX(self, deck: List[int]) -> bool:
        count = {}

        for card in deck:
            count[card] = count.get(card, 0) + 1

        x = 0

        for frequency in count.values():
            x = gcd(x, frequency)

        return x >= 2