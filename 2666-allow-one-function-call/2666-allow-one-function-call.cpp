// 2666-allow-one-function-call
#include <functional>

class Solution {
public:
    std::function<int(int)> once(std::function<int(int)> fn) {
        bool called = false;
        return [called, fn](int x) mutable {
            if (called) return 0;
            called = true;
            return fn(x);
        };
    }
};
