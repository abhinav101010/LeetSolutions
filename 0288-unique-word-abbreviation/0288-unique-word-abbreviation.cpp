#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
using namespace std;

class ValidWordAbbr {
private:
    unordered_map<string, unordered_set<string>> map;
    
    string abbreviate(string word) {
        int n = word.size();
        if (n <= 2) {
            return word;
        }
        return string(1, word[0]) + to_string(n - 2) + string(1, word[n-1]);
    }
public:
    ValidWordAbbr(vector<string>& dictionary) {
        for (string& word : dictionary) {
            string abbr = abbreviate(word);
            map[abbr].insert(word);
        }
    }
    
    bool isUnique(string word) {
        string abbr = abbreviate(word);
        if (map.find(abbr) == map.end()) {
            return true;
        }
        return map[abbr].size() == 1 && map[abbr].find(word) != map[abbr].end();
    }
};

/**
 * Your ValidWordAbbr object will be instantiated and called as such:
 * ValidWordAbbr* obj = new ValidWordAbbr(dictionary);
 * bool param_1 = obj->isUnique(word);
 */
