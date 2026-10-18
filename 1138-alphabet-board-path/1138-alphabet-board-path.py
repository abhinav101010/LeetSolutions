class Solution:
    def alphabetBoardPath(self, target):
        pos={c:(i//5,i%5) for i,c in enumerate("abcdefghijklmnopqrstuvwxyz")}
        ans=[]; cur=(0,0)
        for ch in target:
            r,c=pos[ch]; cr,cc=cur
            if ch=='z':
                ans.append('D'*(r-cr) if r>cr else 'U'*(cr-r))
                ans.append('R'*(c-cc) if c>cc else 'L'*(cc-c))
            else:
                ans.append('R'*(c-cc) if c>cc else 'L'*(cc-c))
                ans.append('D'*(r-cr) if r>cr else 'U'*(cr-r))
            ans.append('!'); cur=(r,c)
        return "".join(ans)
