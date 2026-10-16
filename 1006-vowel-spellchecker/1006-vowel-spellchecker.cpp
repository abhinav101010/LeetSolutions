#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <cctype>
using namespace std;

class Solution {
public:
    vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries) {
        unordered_set<string> exact;
        unordered_map<string, string> caseMap;
        unordered_map<string, string> vowelMap;
        for (const string& word : wordlist) {
            exact.insert(word);
            string lower = toLower(word);
            if (caseMap.find(lower) == caseMap.end()) {
                caseMap[lower] = word;
            }
            string vowelKey = devowel(lower);
            if (vowelMap.find(vowelKey) == vowelMap.end()) {
                vowelMap[vowelKey] = word;
            }
        }
        vector<string> res;
        for (const string& q : queries) {
            if (exact.find(q) != exact.end()) {
                res.push_back(q);
            } else {
                string lower = toLower(q);
                auto it = caseMap.find(lower);
                if (it != caseMap.end()) {
                    res.push_back(it->second);
                } else {
                    string vkey = devowel(lower);
                    auto it2 = vowelMap.find(vkey);
                    if (it2 != vowelMap.end()) {
                        res.push_back(it2->second);
                    } else {
                        res.push_back("");
                    }
                }
            }
        }
        return res;
    }
private:
    string toLower(const string& s) {
        string res = s;
        for (char& c : res) {
            c = tolower(c);
        }
        return res;
    }
    string devowel(const string& s) {
        string res = s;
        for (char& c : res) {
            if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
                c = '*';
            }
        }
        return res;
    }
};
