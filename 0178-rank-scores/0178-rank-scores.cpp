#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <tuple>
#include <cstddef>

using namespace std;

struct Score {
    int id;
    double score;
};

class Solution {
public:
    vector<pair<double, int> > rankScores(vector<Score> &scores) {
        vector<Score> s = scores;
        sort(s.begin(), s.end(), [](const Score &a, const Score &b) {
            if (a.score != b.score) return a.score > b.score;
            return a.id < b.id;
        });
        vector<pair<double, int> > res;
        int rank = 0;
        double prev = -1e18;
        for (const auto &sc : s) {
            if (sc.score != prev) {
                ++rank;
                prev = sc.score;
            }
            res.push_back({sc.score, rank});
        }
        return res;
    }
};
