class Solution:
    def isInterleave(self, s1: str, s2: str, s3: str) -> bool:
# This code didnt work properly, gets new ides of recursion from gpt now implemeting below it
        # if len(s1) + len(s2) != len(s3):
        #     return False

        # while s3:
        #     if s1 and s2 and s1[1] and s2[1] and s3[1] and s3[0] == s1[0] and s3[0] == s2[0]:
        #         if s3[1] == s1[1]:
        #             s1 = s1[1:]
        #             s3 = s3[1:]
        #             continue

        #         if s2 and s3[1] == s2[1]:
        #             s2 = s2[1:]
        #             s3 = s3[1:]
        #             continue

        #     if s1 and s3[0] == s1[0]:
        #         s1 = s1[1:]
        #         s3 = s3[1:]
        #         continue
            
        #     if s2 and s3[0] == s2[0]:
        #         s2 = s2[1:]
        #         s3 = s3[1:]
        #         continue
            
        #     return False
        # return True

        if len(s1) + len(s2) != len(s3):
            return False

        memory = {}

        def matchStr(i, j):
            if (i,j) in memory: return memory[(i,j)]

            if i == len(s1) and j == len(s2):
                return True

            k = i + j

            ans = False
            if i < len(s1) and s1[i] == s3[k]:
                ans = matchStr(i + 1, j)

            if not ans and j < len(s2) and s2[j] == s3[k]:
                ans = matchStr(i, j + 1)

            memory[(i, j)] = ans
            return ans

        return matchStr(0, 0)