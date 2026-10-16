class Solution:
    def spellchecker(self, wordlist, queries):
        exact_set = set(wordlist)
        case_map = {}
        vowel_map = {}
        for word in wordlist:
            lower = word.lower()
            if lower not in case_map:
                case_map[lower] = word
            # vowel-normalized: replace vowels with '*'
            vowel_key = ''.join('*' if c in 'aeiou' else c for c in lower)
            if vowel_key not in vowel_map:
                vowel_map[vowel_key] = word
        def devowel(s):
            return ''.join('*' if c in 'aeiou' else c for c in s.lower())
        res = []
        for q in queries:
            if q in exact_set:
                res.append(q)
            else:
                lower = q.lower()
                if lower in case_map:
                    res.append(case_map[lower])
                else:
                    vkey = devowel(q)
                    if vkey in vowel_map:
                        res.append(vowel_map[vkey])
                    else:
                        res.append("")
        return res
