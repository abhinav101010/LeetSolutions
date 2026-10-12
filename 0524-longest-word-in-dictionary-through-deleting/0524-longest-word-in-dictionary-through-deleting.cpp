class Solution {
public:
    string findLongestWord(string s, vector<string>& dictionary) {
        sort(dictionary.begin(), dictionary.end(), [](const string& a, const string& b) {
            if (a.size() != b.size()) return a.size() > b.size();
            return a < b;
        });
        
        for (const string& word : dictionary) {
            int i = 0;
            for (char c : s) {
                if (i < (int)word.size() && word[i] == c) i++;
            }
            if (i == (int)word.size()) return word;
        }
        return "";
    }
};