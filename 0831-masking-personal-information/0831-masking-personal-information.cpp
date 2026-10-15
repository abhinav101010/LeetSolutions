#include <string>
#include <cctype>
using namespace std;

class Solution {
public:
    string maskPII(string s) {
        if (s.find('@') != string::npos) {
            // email
            for (char &c : s) c = tolower(c);
            int at = s.find('@');
            string name = s.substr(0, at);
            string domain = s.substr(at);
            string maskedName = string(1, name[0]) + "*****" + string(1, name.back());
            return maskedName + domain;
        } else {
            // phone
            string digits;
            for (char c : s) {
                if (isdigit(c)) digits.push_back(c);
            }
            int n = digits.size();
            string local = digits.substr(n-10);
            string country = digits.substr(0, n-10);
            if (country.empty()) {
                return "***-***-" + local.substr(6);
            } else {
                string sb = "+";
                sb.append(country.size(), '*');
                sb += "-***-***-";
                sb += local.substr(6);
                return sb;
            }
        }
    }
};
