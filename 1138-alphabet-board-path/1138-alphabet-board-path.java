class Solution {
    public String alphabetBoardPath(String target) {
        StringBuilder sb=new StringBuilder(); int cr=0,cc=0;
        for(char ch:target.toCharArray()){
            int i=ch-'a', r=i/5, c=i%5;
            if(ch=='z'){sb.append("D".repeat(Math.max(0,r-cr))); if(r<cr) sb.append("U".repeat(cr-r)); sb.append("R".repeat(Math.max(0,c-cc))); if(c<cc) sb.append("L".repeat(cc-c));}
            else{sb.append("R".repeat(Math.max(0,c-cc))); if(c<cc) sb.append("L".repeat(cc-c)); sb.append("D".repeat(Math.max(0,r-cr))); if(r<cr) sb.append("U".repeat(cr-r));}
            sb.append('!'); cr=r; cc=c;
        }
        return sb.toString();
    }}
