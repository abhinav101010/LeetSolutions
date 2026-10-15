#include <vector>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <cctype>
using namespace std;

class Solution {
public:
    vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries) {
        unordered_set<string> wordsPerfect(wordlist.begin(), wordlist.end());
        unordered_map<string, string> wordsCap;
        unordered_map<string, string> wordsVow;
        for (string& w : wordlist) {
            string wlow = toLower(w);
            if (wordsCap.find(wlow) == wordsCap.end()) {
                wordsCap[wlow] = w;
            }
            string wdev = devowel(wlow);
            if (wordsVow.find(wdev) == wordsVow.end()) {
                wordsVow[wdev] = w;
            }
        }
        vector<string> res;
        for (string& q : queries) {
            if (wordsPerfect.find(q) != wordsPerfect.end()) {
                res.push_back(q);
                continue;
            }
            string qlow = toLower(q);
            if (wordsCap.find(qlow) != wordsCap.end()) {
                res.push_back(wordsCap[qlow]);
                continue;
            }
            string qdev = devowel(qlow);
            if (wordsVow.find(qdev) != wordsVow.end()) {
                res.push_back(wordsVow[qdev]);
                continue;
            }
            res.push_back("");
        }
        return res;
    }
private:
    string toLower(string s) {
        for (char& c : s) c = tolower(c);
        return s;
    }
    string devowel(string s) {
        string res;
        for (char c : s) {
            if (string("aeiou").find(c) != string::npos) {
                res += '*';
            } else {
                res += c;
            }
        }
        return res;
    }
};
