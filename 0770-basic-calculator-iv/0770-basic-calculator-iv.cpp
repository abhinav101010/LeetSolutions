#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <cctype>
#include <regex>
#include <map>
using namespace std;

class Polynomial {
public:
    map<vector<string>, int> terms;
    
    void normalize() {
        for (auto it = terms.begin(); it != terms.end(); ) {
            if (it->second == 0) {
                it = terms.erase(it);
            } else {
                ++it;
            }
        }
    }
    
    Polynomial operator+(const Polynomial& other) const {
        Polynomial res;
        for (auto& p : terms) {
            res.terms[p.first] += p.second;
        }
        for (auto& p : other.terms) {
            res.terms[p.first] += p.second;
        }
        res.normalize();
        return res;
    }
    
    Polynomial operator-(const Polynomial& other) const {
        Polynomial res;
        for (auto& p : terms) {
            res.terms[p.first] += p.second;
        }
        for (auto& p : other.terms) {
            res.terms[p.first] -= p.second;
        }
        res.normalize();
        return res;
    }
    
    Polynomial operator*(const Polynomial& other) const {
        Polynomial res;
        for (auto& p1 : terms) {
            for (auto& p2 : other.terms) {
                vector<string> vars = p1.first;
                vars.insert(vars.end(), p2.first.begin(), p2.first.end());
                sort(vars.begin(), vars.end());
                res.terms[vars] += p1.second * p2.second;
            }
        }
        res.normalize();
        return res;
    }
    
    Polynomial constant(int val) {
        terms[vector<string>()] += val;
        normalize();
        return *this;
    }
    
    Polynomial variable(const string& var) {
        terms[vector<string>{var}] += 1;
        normalize();
        return *this;
    }
    
    vector<string> toList() const {
        vector<vector<string>> varsList;
        for (auto& p : terms) {
            varsList.push_back(p.first);
        }
        sort(varsList.begin(), varsList.end(), [](const vector<string>& a, const vector<string>& b) {
            if (a.size() != b.size()) {
                return a.size() > b.size(); // descending degree
            }
            return a < b; // lexicographic
        });
        vector<string> res;
        for (const auto& vars : varsList) {
            int coeff = terms.at(vars);
            if (coeff == 0) continue;
            string term = to_string(coeff);
            if (!vars.empty()) {
                term += "*";
                for (size_t i = 0; i < vars.size(); ++i) {
                    if (i > 0) term += "*";
                    term += vars[i];
                }
            }
            res.push_back(term);
        }
        return res;
    }
};

class Solution {
public:
    vector<string> basicCalculatorIV(string expression, vector<string> evalvars, vector<int> evalints) {
        unordered_map<string, int> evalMap;
        for (int i = 0; i < evalvars.size(); ++i) {
            evalMap[evalvars[i]] = evalints[i];
        }
        // tokenize
        vector<string> tokens;
        regex re(R"(\d+|[a-z]+|[+\-*/()])");
        sregex_iterator it(expression.begin(), expression.end(), re);
        sregex_iterator end;
        for (; it != end; ++it) {
            tokens.push_back(it->str());
        }
        vector<Polynomial> values;
        vector<string> ops;
        map<string, int> precedence = {{"+",1},{"-",1},{"*",2}};
        auto applyOp = [&]() {
            string op = ops.back(); ops.pop_back();
            Polynomial b = values.back(); values.pop_back();
            Polynomial a = values.back(); values.pop_back();
            if (op == "+") {
                values.push_back(a + b);
            } else if (op == "-") {
                values.push_back(a - b);
            } else if (op == "*") {
                values.push_back(a * b);
            }
            // no division
        };
        for (string& token : tokens) {
            if (regex_match(token, regex(R"(\d+)"))) {
                values.push_back(Polynomial().constant(stoi(token)));
            } else if (regex_match(token, regex(R"([a-z]+)"))) {
                if (evalMap.count(token)) {
                    values.push_back(Polynomial().constant(evalMap[token]));
                } else {
                    values.push_back(Polynomial().variable(token));
                }
            } else if (token == "(") {
                ops.push_back(token);
            } else if (token == ")") {
                while (!ops.empty() && ops.back() != "(") {
                    applyOp();
                }
                ops.pop_back(); // remove '('
            } else {
                while (!ops.empty() && ops.back() != "(" && precedence[ops.back()] >= precedence[token]) {
                    applyOp();
                }
                ops.push_back(token);
            }
        }
        while (!ops.empty()) {
            applyOp();
        }
        if (values.empty()) return {};
        return values.back().toList();
    }
};
