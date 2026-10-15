class Solution:
    def spellchecker(self, wordlist: list[str], queries: list[str]) -> list[str]:
        def devowel(w):
            return ''.join('*' if c in 'aeiou' else c for c in w.lower())
        words_perfect = set(wordlist)
        words_cap = {}
        words_vow = {}
        for w in wordlist:
            wlow = w.lower()
            if wlow not in words_cap:
                words_cap[wlow] = w
            wdev = devowel(wlow)
            if wdev not in words_vow:
                words_vow[wdev] = w
        res = []
        for q in queries:
            if q in words_perfect:
                res.append(q)
                continue
            qlow = q.lower()
            if qlow in words_cap:
                res.append(words_cap[qlow])
                continue
            qdev = devowel(qlow)
            if qdev in words_vow:
                res.append(words_vow[qdev])
                continue
            res.append("")
        return res
