class Logger {
public:
    unordered_map<string, int> map;
    Logger() {
        
    }
    bool shouldPrintMessage(int timestamp, string message) {
        if (map.find(message) == map.end() || timestamp - map[message] >= 10) {
            map[message] = timestamp;
            return true;
        }
        return false;
    }
};