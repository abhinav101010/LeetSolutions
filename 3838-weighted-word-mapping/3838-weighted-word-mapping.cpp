class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        string ans;
        for (const string& word : words) {
            int wordWeight = 0;
            for (char c : word) {
                wordWeight += weights[c - 'a'];
            }
            ans += char('z' - (wordWeight % 26));
        }
        return ans;
    }
};