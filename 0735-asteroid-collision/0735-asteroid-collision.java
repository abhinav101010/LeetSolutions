import java.util.*;

class Solution {
    public int[] asteroidCollision(int[] asteroids) {
        List<Integer> stack = new ArrayList<>();
        for (int a : asteroids) {
            boolean alive = true;
            while (alive && a < 0 && !stack.isEmpty() && stack.get(stack.size()-1) > 0) {
                int top = stack.get(stack.size()-1);
                if (top < -a) {
                    stack.remove(stack.size()-1);
                    continue;
                } else if (top == -a) {
                    stack.remove(stack.size()-1);
                }
                alive = false;
            }
            if (alive) {
                stack.add(a);
            }
        }
        int[] res = new int[stack.size()];
        for (int i = 0; i < stack.size(); i++) {
            res[i] = stack.get(i);
        }
        return res;
    }
}
