class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_map<string, int> count;
        vector<string> result;
        for (int i = 0; i + 10 <= (int)s.size(); i++) {
            string seq = s.substr(i, 10);
            if (++count[seq] == 2) result.push_back(seq);
        }
        return result;
    }
};