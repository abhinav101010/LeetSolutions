#include <string>
#include <unordered_map>
using namespace std;

class FileSystem {
private:
    unordered_map<string, int> store;
public:
    FileSystem() {
        store["/"] = 0; // value irrelevant, just to mark existence
    }
    
    bool createPath(string path, int value) {
        if (store.find(path) != store.end()) {
            return false;
        }
        size_t pos = path.rfind('/');
        string parent;
        if (pos == string::npos) {
            parent = "/";
        } else {
            parent = path.substr(0, pos);
            if (parent.empty()) {
                parent = "/";
            }
        }
        if (store.find(parent) == store.end()) {
            return false;
        }
        store[path] = value;
        return true;
    }
    
    int get(string path) {
        auto it = store.find(path);
        if (it == store.end()) {
            return -1;
        }
        return it->second;
    }
};
