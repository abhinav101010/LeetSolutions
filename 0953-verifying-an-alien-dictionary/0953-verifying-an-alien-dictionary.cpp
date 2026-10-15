#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        vector<int> orderMap(26, 0);
        for (int i = 0; i < order.size(); i++) {
            orderMap[order[i] - 'a'] = i;
        }
        for (int i = 0; i < (int)words.size() - 1; i++) {
            if (!lessEqual(words[i], words[i+1], orderMap)) {
                return false;
            }
        }
        return true;
    }
private:
    bool lessEqual(const string& w1, const string& w2, const vector<int>& orderMap) {
        int len = min(w1.size(), w2.size());
        for (int j = 0; j < len; j++) {
            int c1 = w1[j] - 'a';
            int c2 = w2[j] - 'a';
            if (c1 != c2) {
                return orderMap[c1] < orderMap[c2];
            }
        }
        return w1.size() <= w2.size();
    }
};
