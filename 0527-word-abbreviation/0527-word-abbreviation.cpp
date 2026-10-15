#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
private:
    string abbreviate(const string& word, int len) {
        if (word.length() - len <= 2) {
            return word;
        }
        int num = word.length() - len - 1;
        return word.substr(0, len) + to_string(num) + word.back();
    }
public:
    vector<string> wordsAbbreviation(vector<string>& dict) {
        int n = dict.size();
        vector<int> prefix(n, 1);
        vector<string> res = dict;
        bool changed;
        do {
            changed = false;
            unordered_map<string, vector<int>> mp;
            for (int i = 0; i < n; i++) {
                string abbr = abbreviate(dict[i], prefix[i]);
                mp[abbr].push_back(i);
            }
            for (auto& kv : mp) {
                if (kv.second.size() > 1) {
                    changed = true;
                    for (int i : kv.second) {
                        prefix[i]++;
                    }
                }
            }
        } while (changed);
        for (int i = 0; i < n; i++) {
            res[i] = abbreviate(dict[i], prefix[i]);
        }
        return res;
    }
};
