class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        unordered_map<string, int> count;
        auto addWords = [&](const string& s) {
            size_t start = 0;
            while (start < s.size()) {
                size_t end = s.find(' ', start);
                if (end == string::npos) end = s.size();
                count[s.substr(start, end - start)]++;
                start = end + 1;
            }
        };
        addWords(s1);
        addWords(s2);
        
        vector<string> ans;
        for (auto& [word, cnt] : count) {
            if (cnt == 1) ans.push_back(word);
        }
        return ans;
    }
};