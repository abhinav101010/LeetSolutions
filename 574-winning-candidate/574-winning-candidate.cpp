#include <vector>
#include <string>
#include <algorithm>
using namespace std;

struct Candidate { int id; string name; int vote; };

class Solution {
public:
    string winningCandidate(vector<Candidate>& candidates) {
        if (candidates.empty()) return "";
        int maxVote = candidates[0].vote;
        for (auto& c : candidates) maxVote = max(maxVote, c.vote);
        for (auto& c : candidates) if (c.vote == maxVote) return c.name;
        return "";
    }
};
