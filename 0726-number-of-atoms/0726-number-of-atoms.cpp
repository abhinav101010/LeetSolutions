#include <string>
#include <vector>
#include <map>
#include <cctype>
using namespace std;

class Solution {
private:
    // helper to parse number starting at i, returns number and updates i
    int parseNumber(const string& formula, int& i) {
        int start = i;
        while (i < formula.size() && isdigit(formula[i])) {
            i++;
        }
        if (start == i) return 1;
        return stoi(formula.substr(start, i - start));
    }
    // helper to parse element name starting at i, returns name and updates i
    string parseName(const string& formula, int& i) {
        int start = i++;
        // first char already uppercase
        while (i < formula.size() && islower(formula[i])) {
            i++;
        }
        return formula.substr(start, i - start);
    }
    // recursive parse
    map<string, int> parseFormula(const string& formula, int& i) {
        map<string, int> cnt;
        int n = formula.size();
        while (i < n && formula[i] != ')') {
            if (formula[i] == '(') {
                i++; // skip '('
                map<string, int> inner = parseFormula(formula, i);
                int mult = parseNumber(formula, i);
                for (auto& kv : inner) {
                    cnt[kv.first] += kv.second * mult;
                }
            } else {
                string name = parseName(formula, i);
                int num = parseNumber(formula, i);
                cnt[name] += num;
            }
        }
        // skip ')'
        if (i < n && formula[i] == ')') {
            i++;
        }
        return cnt;
    }
public:
    string countOfAtoms(string formula) {
        int idx = 0;
        map<string, int> cnt = parseFormula(formula, idx);
        string res;
        for (auto& kv : cnt) {
            res += kv.first;
            if (kv.second > 1) {
                res += to_string(kv.second);
            }
        }
        return res;
    }
};
