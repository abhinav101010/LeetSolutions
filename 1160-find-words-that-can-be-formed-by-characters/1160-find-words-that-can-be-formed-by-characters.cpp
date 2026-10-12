class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        vector<int> count(26, 0);
        for (char c : chars) {
            count[c - 'a']++;
        }

        int ans = 0;
        for (const string& word : words) {
            vector<int> wordCount(26, 0);
            for (char c : word) {
                wordCount[c - 'a']++;
            }

            bool good = true;
            for (int i = 0; i < 26; i++) {
                if (wordCount[i] > count[i]) {
                    good = false;
                    break;
                }
            }

            if (good) {
                ans += word.length();
            }
        }

        return ans;
    }
};