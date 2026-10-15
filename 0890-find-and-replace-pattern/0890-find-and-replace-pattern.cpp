#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<int> patNorm = normalize(pattern);
        vector<string> res;
        for (string& w : words) {
            if (normalize(w) == patNorm) {
                res.push_back(w);
            }
        }
        return res;
    }
private:
    vector<int> normalize(const string& s) {
        unordered_map<char, int> map;
        vector<int> res;
        for (char ch : s) {
            if (map.find(ch) == map.end()) {
                map[ch] = (int)map.size();
            }
            res.push_back(map[ch]);
        }
        return res;
    }
};
