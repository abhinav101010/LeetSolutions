import random

class Solution:
    def findSecretWord(self, wordlist, master):
        """
        :type wordlist: List[Str]
        :type master: Master
        :rtype: None
        """
        n = len(wordlist)
        candidates = wordlist[:]
        for _ in range(10):  # allowed guesses
            if not candidates:
                break
            # pick random candidate
            guess_word = random.choice(candidates)
            matches = master.guess(guess_word)
            # filter candidates with same match count
            new_candidates = []
            for w in candidates:
                if self.match_count(guess_word, w) == matches:
                    new_candidates.append(w)
            candidates = new_candidates

    def match_count(self, a, b):
        return sum(1 for i in range(len(a)) if a[i] == b[i])
