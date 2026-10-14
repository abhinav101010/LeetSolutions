#include <string>
#include <vector>
#include <map>
using namespace std;

class Solution {
private:
    // helper to parse atom (number or variable) returning value and updating index
    int parseAtom(const string& s, int& i, const vector<map<string,int>>& scopes) {
        int start = i;
        while (i < s.size() && s[i] != ' ' && s[i] != ')') {
            i++;
        }
        string token = s.substr(start, i - start);
        if (isdigit(token[0]) || token[0] == '-') {
            return stoi(token);
        }
        // variable
        for (auto it = scopes.rbegin(); it != scopes.rend(); ++it) {
            auto f = it->find(token);
            if (f != it->end()) {
                return f->second;
            }
        }
        throw invalid_argument("Unknown variable");
    }
    
    int parseExpression(const string& s, int& i, vector<map<string,int>>& scopes) {
        if (s[i] != '(') {
            return parseAtom(s, i, scopes);
        }
        i++; // skip '('
        if (s.substr(i, 3) == "let") {
            i += 3; // skip 'let'
            scopes.push_back(map<string,int>());
            while (true) {
                // skip spaces
                while (i < s.size() && s[i] == ' ') i++;
                // parse variable name
                int varStart = i;
                while (i < s.size() && s[i] != ' ' && s[i] != ')') {
                    i++;
                }
                string var = s.substr(varStart, i - varStart);
                // skip spaces
                while (i < s.size() && s[i] == ' ') i++;
                // if next is ')', then this var is actually the expression
                if (i < s.size() && s[i] == ')') {
                    int val = parseExpression(s, i, scopes);
                    scopes.pop_back();
                    return val;
                }
                // parse expression for value
                int val = parseExpression(s, i, scopes);
                scopes.back()[var] = val;
                // skip spaces
                while (i < s.size() && s[i] == ' ') i++;
            }
        } else if (s.substr(i, 3) == "add") {
            i += 3; // skip 'add'
            while (i < s.size() && s[i] == ' ') i++;
            int a1 = parseExpression(s, i, scopes);
            while (i < s.size() && s[i] == ' ') i++;
            int a2 = parseExpression(s, i, scopes);
            while (i < s.size() && s[i] == ' ') i++;
            i++; // skip ')'
            return a1 + a2;
        } else { // mult
            i += 4; // skip 'mult'
            while (i < s.size() && s[i] == ' ') i++;
            int a1 = parseExpression(s, i, scopes);
            while (i < s.size() && s[i] == ' ') i++;
            int a2 = parseExpression(s, i, scopes);
            while (i < s.size() && s[i] == ' ') i++;
            i++; // skip ')'
            return a1 * a2;
        }
    }
public:
    int evaluate(string expression) {
        int idx = 0;
        vector<map<string,int>> scopes;
        return parseExpression(expression, idx, scopes);
    }
};
