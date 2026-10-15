#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<string> reorderLogFiles(vector<string>& logs) {
        vector<string> letter;
        vector<string> digit;
        for (string& log : logs) {
            int space = log.find(' ');
            string id = log.substr(0, space);
            string rest = log.substr(space+1);
            if (isdigit(rest[0])) {
                digit.push_back(log);
            } else {
                letter.push_back(log);
            }
        }
        auto cmp = [](const string& a, const string& b) {
            int spaceA = a.find(' ');
            string idA = a.substr(0, spaceA);
            string restA = a.substr(spaceA+1);
            int spaceB = b.find(' ');
            string idB = b.substr(0, spaceB);
            string restB = b.substr(spaceB+1);
            int cmp = restA.compare(restB);
            if (cmp != 0) return cmp;
            return idA.compare(idB);
        };
        sort(letter.begin(), letter.end(), cmp);
        letter.insert(letter.end(), digit.begin(), digit.end());
        return letter;
    }
};
