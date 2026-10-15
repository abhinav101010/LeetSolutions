#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

// Dummy Master class; actual definition provided by LeetCode
class Master {
public:
    int guess(string word) {
        return 0;
    }
};

class Solution {
public:
    void findSecretWord(vector<string>& wordlist, Master& master) {
        vector<string> candidates = wordlist;
        srand(time(nullptr));
        for (int i = 0; i < 10; i++) {
            if (candidates.empty()) break;
            int idx = rand() % candidates.size();
            string guessWord = candidates[idx];
            int matches = master.guess(guessWord);
            vector<string> newCandidates;
            for (const string& w : candidates) {
                if (matchCount(guessWord, w) == matches) {
                    newCandidates.push_back(w);
                }
            }
            candidates = newCandidates;
        }
    }
private:
    int matchCount(const string& a, const string& b) {
        int count = 0;
        for (int i = 0; i < a.size(); i++) {
            if (a[i] == b[i]) {
                count++;
            }
        }
        return count;
    }
};
