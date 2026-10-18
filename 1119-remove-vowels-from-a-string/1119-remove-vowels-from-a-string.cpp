class Solution {
public:
    string removeVowels(string s) {
        string ans;
        for(char c:s) if(string("aeiou").find(c)==string::npos) ans+=c;
        return ans;
    }
};