class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        # combo = set()
        # def permute(arr, start):
        #     nonlocal combo
        #     nonlocal strs
        #     if start == len(arr):
        #         if "".join(arr) in strs:
        #             combo.add("".join(arr))
        #         return

        #     for i in range(start, len(arr)):
        #         arr[start],arr[i] = arr[i],arr[start]
        #         permute(arr, start+1)
        #         arr[start],arr[i] = arr[i],arr[start]

        # ans = set()
        # for _ in strs:
        #     combo = set()
        #     permute([*_], 0)
        #     ans.add(tuple(sorted(combo)))

        # return list(ans)

        ans = {}
        pattern = "".join(sorted(strs[0]))
        matches = []

        for word in strs:
            if "".join(sorted(word)) == pattern:
                matches.append(word)
            elif "".join(sorted(word)) in list(ans.keys()):
                ans["".join(sorted(word))].append(word)
            else:
                ans.update({pattern: list(matches)})
                pattern = "".join(sorted(word))
                matches.clear()
                matches.append(word)
        if len(matches) > 0: ans.update({pattern: list(matches)})
        return list(ans.values())









