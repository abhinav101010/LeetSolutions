#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<string> ipToCIDR(string ip, int n) {
        long ipNum = ipToInt(ip);
        vector<string> res;
        while (n > 0) {
            // lowbit
            long lowbit = ipNum & -ipNum;
            // adjust to not exceed n
            while (lowbit > n) {
                lowbit >>= 1;
            }
            int prefix = 32 - (int)(log2(lowbit));
            res.push_back(intToIp(ipNum) + "/" + to_string(prefix));
            ipNum += lowbit;
            n -= lowbit;
        }
        return res;
    }
    
private:
    long ipToInt(string ip) {
        long res = 0;
        size_t start = 0;
        size_t end = ip.find('.');
        while (end != string::npos) {
            res = res * 256 + stol(ip.substr(start, end - start));
            start = end + 1;
            end = ip.find('.', start);
        }
        res = res * 256 + stol(ip.substr(start));
        return res;
    }
    
    string intToIp(long x) {
        return to_string((x >> 24) & 255) + "." +
               to_string((x >> 16) & 255) + "." +
               to_string((x >> 8) & 255) + "." +
               to_string(x & 255);
    }
};
