class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string longestPre;
        int sizeOfFirst = strs[0].length();
        for(int i=0;i<sizeOfFirst;i++){
            bool keepgoing = true;
            for(int j=0;j<strs.size();j++){
                if(strs[0][i] != strs[j][i]){
                    keepgoing = false;
                } 
            }
            if(!keepgoing) break;
            else longestPre += strs[0][i];
        }

        cout << longestPre;
        return longestPre;
    }
};