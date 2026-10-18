#include <vector>
#include <deque>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        int n = deck.size();
        sort(deck.begin(), deck.end());
        deque<int> q;
        for (int i = 0; i < n; i++) q.push_back(i);
        vector<int> ans(n);
        for (int card : deck) {
            int idx = q.front(); q.pop_front();
            ans[idx] = card;
            if (!q.empty()) {
                q.push_back(q.front()); q.pop_front();
            }
        }
        return ans;
    }
};
