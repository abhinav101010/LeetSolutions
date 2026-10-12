/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Constructor initializes an empty nested list.
 *     NestedInteger();
 *
 *     // Constructor initializes a single integer.
 *     NestedInteger(int value);
 *
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Set this NestedInteger to hold a single integer.
 *     void setInteger(int value);
 *
 *     // Set this NestedInteger to hold a nested list and adds a nested integer to it.
 *     void add(const NestedInteger &ni);
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
class Solution {
public:
    NestedInteger deserialize(string s) {
        if (s.empty() || s[0] != '[') {
            return NestedInteger(stoi(s));
        }
        
        vector<NestedInteger> stack;
        int num = 0;
        int sign = 1;
        bool hasNum = false;
        
        for (char c : s) {
            if (c == '[') {
                stack.emplace_back();
            } else if (c == ']') {
                if (hasNum) {
                    stack.back().add(NestedInteger(sign * num));
                    num = 0;
                    sign = 1;
                    hasNum = false;
                }
                if (stack.size() > 1) {
                    NestedInteger top = stack.back();
                    stack.pop_back();
                    stack.back().add(top);
                }
            } else if (c == ',') {
                if (hasNum) {
                    stack.back().add(NestedInteger(sign * num));
                    num = 0;
                    sign = 1;
                    hasNum = false;
                }
            } else if (c == '-') {
                sign = -1;
            } else {
                num = num * 10 + (c - '0');
                hasNum = true;
            }
        }
        
        return stack.back();
    }
};