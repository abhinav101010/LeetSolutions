#include <string>
using namespace std;
class StringIterator {
    string s;
    int i, cnt;
    char ch;
public:
    StringIterator(string compressedString) {
        s = compressedString; i = 0; cnt = 0; ch = ' ';
    }
    char next() {
        if (hasNext()) {
            cnt--;
            return ch;
        }
        return ' ';
    }
    bool hasNext() {
        if (cnt > 0) return true;
        if (i >= s.size()) return false;
        ch = s[i++];
        int j = i;
        while (j < s.size() && isdigit(s[j])) j++;
        cnt = stoi(s.substr(i, j-i));
        i = j;
        return true;
    }
};
