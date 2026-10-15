#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
private:
    bool backtrack(int idx, const vector<vector<pair<string,string>>>& splits,
                   unordered_map<string,int>& leftCnt,
                   unordered_map<string,int>& rightCnt) {
        if (idx == splits.size()) {
            return leftCnt == rightCnt;
        }
        for (const auto& p : splits[idx]) {
            const string& left = p.first;
            const string& right = p.second;
            leftCnt[left]++;
            rightCnt[right]++;
            if (backtrack(idx+1, splits, leftCnt, rightCnt)) {
                return true;
            }
            // undo
            leftCnt[left]--;
            if (leftCnt[left] == 0) {
                leftCnt.erase(left);
            }
            rightCnt[right]--;
            if (rightCnt[right] == 0) {
                rightCnt.erase(right);
            }
        }
        return false;
    }
public:
    bool splitConcat(vector<string>& strs) {
        vector<vector<pair<string,string>>> splits;
        for (const string& s : strs) {
            vector<pair<string,string>> cur;
            for (int i = 1; i < (int)s.size(); i++) {
                cur.push_back({s.substr(0, i), s.substr(i)});
            }
            splits.push_back(cur);
        }
        unordered_map<string,int> leftCnt, rightCnt;
        return backtrack(0, splits, leftCnt, rightCnt);
    }
};
