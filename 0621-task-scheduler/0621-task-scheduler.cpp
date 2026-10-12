class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> count(26, 0);
        for (char c : tasks) count[c - 'A']++;
        
        priority_queue<int> maxHeap;
        for (int freq : count) if (freq > 0) maxHeap.push(freq);
        
        int time = 0;
        queue<pair<int, int>> waitQueue;
        
        while (!maxHeap.empty() || !waitQueue.empty()) {
            time++;
            
            if (!maxHeap.empty()) {
                int freq = maxHeap.top() - 1;
                maxHeap.pop();
                if (freq > 0) waitQueue.push({time + n, freq});
            }
            
            if (!waitQueue.empty() && waitQueue.front().first == time) {
                maxHeap.push(waitQueue.front().second);
                waitQueue.pop();
            }
        }
        
        return time;
    }
};