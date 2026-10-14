#include <vector>
using namespace std;

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> stack;
        for (int a : asteroids) {
            bool alive = true;
            while (alive && a < 0 && !stack.empty() && stack.back() > 0) {
                int top = stack.back();
                if (top < -a) {
                    stack.pop_back();
                    continue;
                } else if (top == -a) {
                    stack.pop_back();
                }
                alive = false;
            }
            if (alive) {
                stack.push_back(a);
            }
        }
        return stack;
    }
};
