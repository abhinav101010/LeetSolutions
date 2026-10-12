class Codec {
private:
    unordered_map<string, string> urlToCode;
    unordered_map<string, string> codeToUrl;
    string chars = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
    string base = "http://tinyurl.com/";

public:
    string encode(string longUrl) {
        if (urlToCode.count(longUrl)) return base + urlToCode[longUrl];
        string code;
        do {
            code.clear();
            for (int i = 0; i < 6; i++) {
                code += chars[rand() % chars.size()];
            }
        } while (codeToUrl.count(code));
        urlToCode[longUrl] = code;
        codeToUrl[code] = longUrl;
        return base + code;
    }

    string decode(string shortUrl) {
        string code = shortUrl.substr(base.size());
        return codeToUrl.count(code) ? codeToUrl[code] : "";
    }
};