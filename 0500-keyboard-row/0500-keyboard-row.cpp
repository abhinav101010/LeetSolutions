class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        unordered_set<char> row1 = {'q','w','e','r','t','y','u','i','o','p'};
        unordered_set<char> row2 = {'a','s','d','f','g','h','j','k','l'};
        unordered_set<char> row3 = {'z','x','c','v','b','n','m'};
        
        vector<string> ans;
        for (const string& word : words) {
            bool inRow1 = true, inRow2 = true, inRow3 = true;
            for (char c : word) {
                char lower = tolower(c);
                if (!row1.count(lower)) inRow1 = false;
                if (!row2.count(lower)) inRow2 = false;
                if (!row3.count(lower)) inRow3 = false;
            }
            if (inRow1 || inRow2 || inRow3) {
                ans.push_back(word);
            }
        }
        return ans;
    }
};