#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<string> removeComments(vector<string>& source) {
        bool inBlock = false;
        vector<string> ans;
        for (string& line : source) {
            int i = 0;
            string cur;
            while (i < line.size()) {
                if (!inBlock && i + 1 < line.size() && line[i] == '/' && line[i+1] == '*') {
                    inBlock = true;
                    i += 2;
                } else if (!inBlock && i + 1 < line.size() && line[i] == '/' && line[i+1] == '/') {
                    break;
                } else if (inBlock && i + 1 < line.size() && line[i] == '*' && line[i+1] == '/') {
                    inBlock = false;
                    i += 2;
                } else if (!inBlock) {
                    cur += line[i];
                    i++;
                } else {
                    i++;
                }
            }
            if (!inBlock && !cur.empty()) {
                ans.push_back(cur);
            }
        }
        return ans;
    }
};
