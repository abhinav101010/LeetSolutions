class Solution {
public:
    string alphabetBoardPath(string target) {
        auto pos=[](char c){int i=c-'a'; return make_pair(i/5,i%5);};
        string ans; int cr=0,cc=0;
        for(char ch:target){
            auto [r,c]=pos(ch);
            if(ch=='z'){ans+=string(r-cr,'D'); if(r<cr) ans+=string(cr-r,'U'); ans+=string(c-cc,'R'); if(c<cc) ans+=string(cc-c,'L');}
            else{ans+=string(c-cc,'R'); if(c<cc) ans+=string(cc-c,'L'); ans+=string(r-cr,'D'); if(r<cr) ans+=string(cr-r,'U');}
            ans+='!'; cr=r; cc=c;
        }
        return ans;
    }}
