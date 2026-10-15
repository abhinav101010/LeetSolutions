#include <vector>
#include <deque>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        int n = deck.size();
        sort(deck.begin(), deck.end());
        vector<int> res(n, 0);
        deque<int> idx;
        for (int i = 0; i < n; i++) {
            idx.push_back(i);
        }
        for (int card : deck) {
            int i = idx.front();
            idx.pop_front();
            res[i] = card;
            if (!idx.empty()) {
                idx.push_back(idx.front());
                idx.pop_front();
            }
        }
        return res;
    }
};
