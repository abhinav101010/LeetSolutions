#include <vector>
#include <string>
#include <set>
using namespace std;
class Solution {
    set<string> res;
    vector<string> parseExpr(const string& e, int start, int end) {
        vector<string> cur{""};
        int i = start;
        while (i < end) {
            char c = e[i];
            if (c == '{') {
                int j = i+1, depth = 1;
                while (depth) { if (e[j]=='{') depth++; else if (e[j]=='}') depth--; j++; }
                vector<string> inner = parseExpr(e, i+1, j-1);
                vector<string> nxt;
                for (auto& a : cur) for (auto& b : inner) nxt.push_back(a+b);
                cur = nxt; i = j;
            } else if (c == ',') {
                break;
            } else {
                for (auto& s : cur) s += c;
                i++;
            }
        }
        return cur;
    }
public:
    vector<string> braceExpansionII(string expression) {
        vector<string> words = parseExpr(expression, 0, expression.size());
        for (auto& s : words) res.insert(s);
        return vector<string>(res.begin(), res.end());
    }
};
