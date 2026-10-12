class Solution:
    def getHint(self, secret: str, guess: str) -> str:
        bulls = 0
        cows = 0

        secretLeft = []
        guessLeft = []

        for i in range(len(secret)):
            if secret[i] == guess[i]:
                bulls += 1
            else:
                secretLeft.append(secret[i])
                guessLeft.append(guess[i])

        for c in guessLeft:
            if c in secretLeft:
                cows += 1
                secretLeft.remove(c)

        return str(bulls) + "A" + str(cows) + "B"