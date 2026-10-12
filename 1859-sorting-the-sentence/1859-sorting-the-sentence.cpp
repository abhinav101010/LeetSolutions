#include <string>
#include <vector>
#include <sstream>
using namespace std;

class Solution {
public:
    string sortSentence(string s) {
        vector<string> words;
        stringstream ss(s);
        string word;
        while (ss >> word) {
            words.push_back(word);
        }
        vector<string> result(words.size());
        for (const string& w : words) {
            int position = w.back() - '0';
            result[position - 1] = w.substr(0, w.size() - 1);
        }
        string ans;
        for (int i = 0; i < result.size(); ++i) {
            if (i > 0) ans += " ";
            ans += result[i];
        }
        return ans;
    }
};