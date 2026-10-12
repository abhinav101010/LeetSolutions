class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        vector<int> common(26, 1000000000);
        for (const auto& word : words) {
            vector<int> count(26, 0);
            for (char ch : word) {
                count[ch - 'a']++;
            }
            for (int i = 0; i < 26; i++) {
                common[i] = min(common[i], count[i]);
            }
        }
        vector<string> ans;
        for (int i = 0; i < 26; i++) {
            for (int j = 0; j < common[i]; j++) {
                ans.push_back(string(1, 'a' + i));
            }
        }
        return ans;
    }
};
