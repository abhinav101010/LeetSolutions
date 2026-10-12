class Solution {
public:
    string complexNumberMultiply(string num1, string num2) {
        num1.pop_back();
        num2.pop_back();
        int a = stoi(num1.substr(0, num1.find('+')));
        int b = stoi(num1.substr(num1.find('+') + 1));
        int c = stoi(num2.substr(0, num2.find('+')));
        int d = stoi(num2.substr(num2.find('+') + 1));
        int real = a * c - b * d;
        int imag = a * d + b * c;
        return to_string(real) + "+" + to_string(imag) + "i";
    }
};