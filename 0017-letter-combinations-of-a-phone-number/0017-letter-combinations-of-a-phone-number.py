class Solution:
    def letterCombinations(self, digits: str) -> List[str]:
        rel = {
            "0":[""],
            "1":[""],
            "2":["a","b","c"],
            "3":["d","e","f"],
            "4":["g","h","i"],
            "5":["j","k","l"],
            "6":["m","n","o"],
            "7":["p","q","r","s"],
            "8":["t","u","v"],
            "9":["w","x","y","z"],
        }

        ans = [""]
        for d in digits:
            newAns = []
            for prefix in ans:
                for c in rel[d]:
                    newAns.append(str(prefix+c))
            ans = newAns

        return ans
        