#include <string>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    string reorganizeString(string s) {
        vector<int> cnt(26, 0);
        for (char c : s) {
            cnt[c - 'a']++;
        }
        priority_queue<pair<int, int>> pq; // max heap by freq
        for (int i = 0; i < 26; i++) {
            if (cnt[i] > 0) {
                pq.push({cnt[i], i});
            }
        }
        string sb;
        pair<int, int> prev = {-1, -1}; // freq, charIndex
        while (!pq.empty()) {
            auto cur = pq.top(); pq.pop();
            sb.push_back('a' + cur.second);
            cur.first--;
            if (prev.first > 0) {
                pq.push(prev);
            }
            prev = cur;
        }
        if (sb.size() != s.size()) {
            return "";
        }
        return sb;
    }
};
