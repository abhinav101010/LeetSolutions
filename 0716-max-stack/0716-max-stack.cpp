#include <stack>
#include <vector>
using namespace std;

class MaxStack {
private:
    stack<int> st;
    stack<int> maxSt;
public:
    MaxStack() {
        
    }
    
    void push(int x) {
        st.push(x);
        if (maxSt.empty() || x >= maxSt.top()) {
            maxSt.push(x);
        } else {
            maxSt.push(maxSt.top());
        }
    }
    
    int pop() {
        maxSt.pop();
        int val = st.top();
        st.pop();
        return val;
    }
    
    int top() {
        return st.top();
    }
    
    int peekMax() {
        return maxSt.top();
    }
    
    int popMax() {
        int maxVal = maxSt.top();
        vector<int> buffer;
        while (st.top() != maxVal) {
            buffer.push_back(st.top());
            st.pop();
            maxSt.pop();
        }
        st.pop(); // pop the max
        maxSt.pop();
        // push back buffered elements
        for (int i = buffer.size() - 1; i >= 0; i--) {
            push(buffer[i]);
        }
        return maxVal;
    }
};

/**
 * Your MaxStack object will be instantiated and called as such:
 * MaxStack* obj = new MaxStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->peekMax();
 * obj->popMax();
 */
