#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        int count = 0;
        for (const string& word : words) {
            if (isSubseq(s, word)) {
                count++;
            }
        }
        return count;
    }
private:
    bool isSubseq(const string& s, const string& word) {
        int i = 0;
        for (char c : s) {
            if (i < word.size() && word[i] == c) {
                i++;
            }
        }
        return i == word.size();
    }
};
