#include <string>
#include <cmath>
#include <algorithm>
using namespace std;

class Solution {
public:
    string similarRGB(string color) {
        string r = similar(color.substr(1, 2));
        string g = similar(color.substr(3, 2));
        string b = similar(color.substr(5, 2));
        return "#" + r + g + b;
    }
private:
    string similar(string s) {
        int val = stoi(s, nullptr, 16);
        int nearest = (int) round(val / 17.0) * 17;
        if (nearest < 0) nearest = 0;
        if (nearest > 255) nearest = 255;
        int digit = nearest / 17;
        char hex = "0123456789abcdef"[digit];
        return string(1, hex) + string(1, hex);
    }
};
