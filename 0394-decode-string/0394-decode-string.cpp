class Solution {
public:
    string decodeString(string s) {
        vector<string> strStack;
        vector<int> numStack;
        string currStr = "";
        int currNum = 0;
        
        for (char c : s) {
            if (isdigit(c)) {
                currNum = currNum * 10 + (c - '0');
            } else if (c == '[') {
                strStack.push_back(currStr);
                numStack.push_back(currNum);
                currStr = "";
                currNum = 0;
            } else if (c == ']') {
                string prevStr = strStack.back();
                strStack.pop_back();
                int num = numStack.back();
                numStack.pop_back();
                string repeated = currStr;
                for (int i = 1; i < num; i++) {
                    repeated += currStr;
                }
                currStr = prevStr + repeated;
            } else {
                currStr += c;
            }
        }
        
        return currStr;
    }
};