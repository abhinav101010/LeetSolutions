// 2666-allow-one-function-call
import java.util.function.Function;

class Solution {
    private boolean called = false;
    
    public Function<Integer, Integer> once(Function<Integer, Integer> fn) {
        return (x) -> {
            if (called) return 0;
            called = true;
            return fn.apply(x);
        };
    }
}
