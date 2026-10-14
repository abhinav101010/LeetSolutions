#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

class WordFilter {
private:
    unordered_map<string, int> mp;
public:
    WordFilter(vector<string> words) {
        for (int weight = 0; weight < words.size(); weight++) {
            string word = words[weight];
            int n = word.size();
            for (int i = 0; i <= n; i++) {
                string pre = word.substr(0, i);
                for (int j = 0; j <= n; j++) {
                    string suf = word.substr(j);
                    string key = pre + "#" + suf;
                    mp[key] = weight;
                }
            }
        }
    }

    int f(string prefix, string suffix) {
        string key = prefix + "#" + suffix;
        auto it = mp.find(key);
        if (it != mp.end()) return it->second;
        return -1;
    }
};
