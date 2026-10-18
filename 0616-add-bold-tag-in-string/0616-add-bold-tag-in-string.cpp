#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    string addBoldTag(string s, vector<string>& dict) {
        int n = s.size();
        vector<bool> bold(n, false);
        for (string& word : dict) {
            size_t start = s.find(word);
            while (start != string::npos) {
                for (size_t i = start; i < start + word.size() && i < s.size(); ++i) {
                    bold[i] = true;
                }
                start = s.find(word, start + 1);
            }
        }
        string res;
        int i = 0;
        while (i < n) {
            if (bold[i]) {
                res += "<b>";
                while (i < n && bold[i]) {
                    res += s[i];
                    i++;
                }
                res += "</b>";
            } else {
                res += s[i];
                i++;
            }
        }
        return res;
    }
};
