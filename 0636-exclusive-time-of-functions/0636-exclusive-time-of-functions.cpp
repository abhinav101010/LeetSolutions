class Solution {
public:
    vector<int> exclusiveTime(int n, vector<string>& logs) {
        vector<int> ans(n, 0);
        stack<int> st;
        int prevTs = 0;
        
        for (const string& log : logs) {
            int pos1 = log.find(':');
            int pos2 = log.rfind(':');
            int fid = stoi(log.substr(0, pos1));
            string event = log.substr(pos1 + 1, pos2 - pos1 - 1);
            int ts = stoi(log.substr(pos2 + 1));
            
            if (event == "start") {
                if (!st.empty()) {
                    ans[st.top()] += ts - prevTs;
                }
                st.push(fid);
                prevTs = ts;
            } else {
                ans[st.top()] += ts - prevTs + 1;
                st.pop();
                prevTs = ts + 1;
            }
        }
        
        return ans;
    }
};