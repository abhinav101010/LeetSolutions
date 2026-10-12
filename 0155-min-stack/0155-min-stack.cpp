class MinStack {
private:
    vector<int> stack;
    vector<int> minStack;
    
public:
    MinStack() {}
    
    void push(int val) {
        stack.push_back(val);
        if (minStack.empty() || val <= minStack.back()) {
            minStack.push_back(val);
        }
    }
    
    void pop() {
        if (!stack.empty()) {
            int val = stack.back();
            stack.pop_back();
            if (!minStack.empty() && val == minStack.back()) {
                minStack.pop_back();
            }
        }
    }
    
    int top() {
        return stack.empty() ? -1 : stack.back();
    }
    
    int getMin() {
        return minStack.empty() ? -1 : minStack.back();
    }
};