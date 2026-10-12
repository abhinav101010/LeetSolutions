class Solution {
public:
    string validIPAddress(string queryIP) {
        if (isIPv4(queryIP)) return "IPv4";
        if (isIPv6(queryIP)) return "IPv6";
        return "Neither";
    }
    
private:
    bool isIPv4(string ip) {
        vector<string> parts = split(ip, '.');
        if (parts.size() != 4) return false;
        for (string part : parts) {
            if (part.empty() || part.size() > 3 || (part[0] == '0' && part.size() > 1)) return false;
            for (char ch : part) if (!isdigit(ch)) return false;
            int val = stoi(part);
            if (val < 0 || val > 255) return false;
        }
        return true;
    }
    
    bool isIPv6(string ip) {
        vector<string> parts = split(ip, ':');
        if (parts.size() != 8) return false;
        for (string part : parts) {
            if (part.empty() || part.size() > 4) return false;
            for (char ch : part) {
                if (!isxdigit(ch)) return false;
            }
        }
        return true;
    }
    
    vector<string> split(const string& s, char delim) {
        vector<string> result;
        stringstream ss(s);
        string token;
        while (getline(ss, token, delim)) {
            result.push_back(token);
        }
        return result;
    }
};