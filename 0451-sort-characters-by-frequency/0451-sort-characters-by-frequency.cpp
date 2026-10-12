class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> count;
        for (char c : s) count[c]++;
        
        vector<pair<char, int>> vec(count.begin(), count.end());
        sort(vec.begin(), vec.end(), [](const auto& a, const auto& b) {
            return a.second > b.second;
        });
        
        string result;
        for (auto& [c, freq] : vec) {
            result += string(freq, c);
        }
        return result;
    }
};