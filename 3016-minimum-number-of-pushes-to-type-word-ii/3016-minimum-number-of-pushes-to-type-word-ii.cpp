class Solution {
public:
    int minimumPushes(string word) {
        vector<int> count(26, 0);
        for (char c : word) {
            count[c - 'a']++;
        }
        sort(count.begin(), count.end(), greater<int>());
        int ans = 0;
        for (int i = 0; i < 26; i++) {
            int pushes = i / 8 + 1;
            ans += count[i] * pushes;
        }
        return ans;
    }
};