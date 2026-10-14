#include <string>
using namespace std;

class StringIterator {
private:
    string s;
    int i;
    char currChar;
    int currCount;
public:
    StringIterator(string compressedString) {
        s = compressedString;
        i = 0;
        currChar = 0;
        currCount = 0;
    }
    
    char next() {
        if (!hasNext()) {
            return ' ';
        }
        if (currCount == 0) {
            currChar = s[i];
            i++;
            int start = i;
            while (i < s.size() && isdigit(s[i])) {
                i++;
            }
            currCount = stoi(s.substr(start, i - start));
        }
        currCount--;
        return currChar;
    }
    
    bool hasNext() {
        return i < s.size() || currCount > 0;
    }
};
