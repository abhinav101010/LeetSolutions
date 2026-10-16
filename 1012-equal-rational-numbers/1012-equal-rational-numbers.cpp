#include <string>
using namespace std;
class Solution {
public:
    bool isRationalEqual(string s, string t) {
        return f(s) == f(t);
    }
private:
    double f(string s) {
        int i = s.find('.');
        if (i == string::npos) return stod(s);
        string intPart = s.substr(0, i);
        string frac = s.substr(i+1);
        int j = frac.find('(');
        if (j == string::npos) {
            return stod(intPart + '.' + frac);
        }
        string nonrep = frac.substr(0, j);
        string rep = frac.substr(j+1, frac.size()-j-2);
        string fullFrac = nonrep + rep + rep + rep + rep + rep + rep + rep + rep + rep;
        return stod(intPart + '.' + fullFrac.substr(0, min((int)fullFrac.size(), 12)));
    }
};
