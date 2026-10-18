class Solution {
    public String removeVowels(String s) {
        StringBuilder sb=new StringBuilder();
        for(char c:s.toCharArray()) if("aeiou".indexOf(c)<0) sb.append(c);
        return sb.toString();
    }
}