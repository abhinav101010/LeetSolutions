class Solution:
    def generateParenthesis(self, n: int) -> List[str]:
        ans = []

        def gen(s, openP, closeP):
            if closeP == n: 
                ans.append(s)
                return

            if s[len(s)-1] == "(" :
                if openP>closeP:
                    gen(s+")", openP, closeP+1)
                if openP<n:
                    gen(s+"(", openP+1, closeP)

            if s[len(s)-1] == ")":
                if openP>closeP: 
                    gen(s+")", openP, closeP+1)
                if openP<n:
                    gen(s+"(", openP+1, closeP)

        gen("(", 1, 0)
        return ans