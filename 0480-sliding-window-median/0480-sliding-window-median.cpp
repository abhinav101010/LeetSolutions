class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        priority_queue<int> maxHeap;
        priority_queue<int, vector<int>, greater<int>> minHeap;
        vector<double> result;
        
        for (int i = 0; i < (int)nums.size(); i++) {
            addNum(nums[i], maxHeap, minHeap);
            balanceHeaps(maxHeap, minHeap);
            
            if (i >= k) {
                removeNum(nums[i - k], maxHeap, minHeap);
                balanceHeaps(maxHeap, minHeap);
            }
            
            if (i >= k - 1) {
                result.push_back(getMedian(maxHeap, minHeap, k));
            }
        }
        
        return result;
    }
    
private:
    void addNum(int num, priority_queue<int>& maxHeap, priority_queue<int, vector<int>, greater<int>>& minHeap) {
        if (maxHeap.empty() || num <= maxHeap.top()) {
            maxHeap.push(num);
        } else {
            minHeap.push(num);
        }
    }
    
    void removeNum(int num, priority_queue<int>& maxHeap, priority_queue<int, vector<int>, greater<int>>& minHeap) {
        // Note: This is O(n) removal. For better performance, use delayed removal with hash map.
        // For simplicity in this solution, we'll rebuild the heap.
        if (!maxHeap.empty() && num <= maxHeap.top()) {
            vector<int> temp;
            while (!maxHeap.empty() && maxHeap.top() != num) {
                temp.push_back(maxHeap.top());
                maxHeap.pop();
            }
            if (!maxHeap.empty()) maxHeap.pop();
            for (int v : temp) maxHeap.push(v);
        } else {
            vector<int> temp;
            while (!minHeap.empty() && minHeap.top() != num) {
                temp.push_back(minHeap.top());
                minHeap.pop();
            }
            if (!minHeap.empty()) minHeap.pop();
            for (int v : temp) minHeap.push(v);
        }
    }
    
    void balanceHeaps(priority_queue<int>& maxHeap, priority_queue<int, vector<int>, greater<int>>& minHeap) {
        while (maxHeap.size() > minHeap.size() + 1) {
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        }
        while (minHeap.size() > maxHeap.size()) {
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
    }
    
    double getMedian(priority_queue<int>& maxHeap, priority_queue<int, vector<int>, greater<int>>& minHeap, int k) {
        if (k % 2 == 1) return maxHeap.top();
        return (maxHeap.top() + minHeap.top()) / 2.0;
    }
};