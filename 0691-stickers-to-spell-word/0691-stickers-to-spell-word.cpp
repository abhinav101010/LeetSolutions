#include <vector>
#include <string>
#include <unordered_map>
#include <queue>
#include <algorithm>
#include <sstream>
#include <cctype>
using namespace std;

class Solution {
public:
    int minStickers(vector<string>& stickers, string target) {
        // Count letters in target
        vector<int> targetCount(26, 0);
        for (char c : target) {
            targetCount[c - 'a']++;
        }
        // List of letters that appear in target
        vector<char> letters;
        for (int i = 0; i < 26; i++) {
            if (targetCount[i] > 0) {
                letters.push_back('a' + i);
            }
        }
        if (letters.empty()) {
            return 0;
        }
        // Preprocess stickers: only keep counts for letters in target
        vector<vector<int>> stickersCounts;
        for (string& s : stickers) {
            vector<int> cnt(26, 0);
            for (char c : s) {
                cnt[c - 'a']++;
            }
            bool has = false;
            vector<int> filtered(26, 0);
            for (char c : letters) {
                int idx = c - 'a';
                if (cnt[idx] > 0) {
                    filtered[idx] = cnt[idx];
                    has = true;
                }
            }
            if (has) {
                stickersCounts.push_back(filtered);
            }
        }
        if (stickersCounts.empty()) {
            return -1;
        }
        // Helper to convert state vector to string
        auto stateToString = [&](const vector<int>& state) {
            string res;
            for (char c : letters) {
                res += to_string(state[c - 'a']) + ",";
            }
            return res;
        };
        // Initial state
        vector<int> start(26, 0);
        for (int i = 0; i < 26; i++) {
            start[i] = targetCount[i];
        }
        string startStr = stateToString(start);
        // BFS
        queue<pair<string, int>> q; // state, steps
        unordered_map<string, int> dist;
        q.push({startStr, 0});
        dist[startStr] = 0;
        while (!q.empty()) {
            auto curr = q.front(); q.pop();
            string stateStr = curr.first;
            int steps = curr.second;
            // Parse stateStr to get current counts
            vector<int> currCnt(26, 0);
            stringstream ss(stateStr);
            string token;
            int idx = 0;
            while (getline(ss, token, ',')) {
                if (!token.empty()) {
                    currCnt[letters[idx] - 'a'] = stoi(token);
                }
                idx++;
            }
            // Check if done
            bool done = true;
            for (int v : currCnt) {
                if (v > 0) {
                    done = false;
                    break;
                }
            }
            if (done) {
                return steps;
            }
            // Find first character with positive count
            char first = 0;
            for (char c : letters) {
                if (currCnt[c - 'a'] > 0) {
                    first = c;
                    break;
                }
            }
            // Try each sticker that has the first letter
            for (auto& sticker : stickersCounts) {
                if (sticker[first - 'a'] == 0) {
                    continue;
                }
                vector<int> nextCnt = currCnt;
                for (int i = 0; i < 26; i++) {
                    if (sticker[i] > 0) {
                        nextCnt[i] = max(0, nextCnt[i] - sticker[i]);
                    }
                }
                string nextStr = stateToString(nextCnt);
                if (dist.find(nextStr) == dist.end() || dist[nextStr] > steps + 1) {
                    dist[nextStr] = steps + 1;
                    q.push({nextStr, steps + 1});
                }
            }
        }
        return -1;
    }
};
