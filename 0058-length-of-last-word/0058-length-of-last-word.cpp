class Solution {
public:
    int lengthOfLastWord(string s) {
        int i = s.length();
        int size = 0;
        while(i){
            --i;
            if(!size && s[i] == ' ') continue;
            else if (size && s[i] == ' ') break;
            size++;
        }
        return size;
    }
};