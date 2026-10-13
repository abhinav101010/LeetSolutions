class Solution {
public:
    string rearrangeString(string s, int k) {
        if (k <= 1) return s;
        vector<int> count(26, 0);
        for (char c : s) count[c - 'a']++;
        priority_queue<pair<int,int>> pq;
        for (int i = 0; i < 26; i++) {
            if (count[i] > 0) pq.push({count[i], i});
        }
        string res;
        queue<pair<int,int>> wait;
        while (!pq.empty()) {
            auto [cCount, c] = pq.top(); pq.pop();
            res += char('a' + c);
            wait.push({cCount - 1, c});
            if ((int)wait.size() == k) {
                auto [wc, cc] = wait.front(); wait.pop();
                if (wc > 0) pq.push({wc, cc});
            }
        }
        return res.size() == s.size() ? res : "";
    }
};