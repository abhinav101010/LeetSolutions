class Solution {
public:
    vector<int> count(const string& exp) {
        int coeff = 0, constant = 0;
        int i = 0, n = exp.size();
        while (i < n) {
            char c = exp[i];
            int sign = 1;
            if (c == '+' || c == '-') {
                sign = (c == '-') ? -1 : 1;
                i++;
                if (i == n) break;
            }
            c = exp[i];
            if (isdigit(c)) {
                int j = i;
                while (j < n && isdigit(exp[j])) j++;
                int num = stoi(exp.substr(i, j - i));
                if (j < n && exp[j] == 'x') {
                    coeff += sign * num;
                    i = j + 1;
                } else {
                    constant += sign * num;
                    i = j;
                }
            } else if (c == 'x') {
                coeff += sign;
                i++;
            } else {
                i++;
            }
        }
        return {coeff, constant};
    }
    
    string solveEquation(string equation) {
        int eqPos = equation.find('=');
        string left = equation.substr(0, eqPos);
        string right = equation.substr(eqPos + 1);
        auto cl = count(left);
        auto cr = count(right);
        int coeff = cl[0] - cr[0];
        int constant = cr[1] - cl[1];
        if (coeff == 0 && constant == 0) return "Infinite solutions";
        if (coeff == 0 && constant != 0) return "No solution";
        return "x=" + to_string(constant / coeff);
    }
};