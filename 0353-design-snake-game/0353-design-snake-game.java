import java.util.*;

class SnakeGame {
    private Deque<int[]> snake;
    private Set<Integer> snakeSet;
    private int[] head;
    private int width, height;
    private int[][] food;
    private int foodIndex;
    
    public SnakeGame(int width, int height, int[][] food) {
        this.width = width;
        this.height = height;
        this.food = food;
        snake = new LinkedList<>();
        head = new int[]{0, 0};
        snake.addLast(new int[]{0, 0});
        snakeSet = new HashSet<>();
        snakeSet.add(0 * width + 0);
        foodIndex = 0;
    }
    
    public int move(String direction) {
        switch (direction) {
            case "U": head[0]--; break;
            case "D": head[0]++; break;
            case "L": head[1]--; break;
            case "R": head[1]++; break;
        }
        if (head[0] < 0 || head[0] >= height || head[1] < 0 || head[1] >= width) return -1;
        int headKey = head[0] * width + head[1];
        if (foodIndex < food.length && head[0] == food[foodIndex][0] && head[1] == food[foodIndex][1]) {
            foodIndex++;
        } else {
            int[] tail = snake.pollFirst();
            snakeSet.remove(tail[0] * width + tail[1]);
        }
        if (snakeSet.contains(headKey)) return -1;
        snake.addLast(new int[]{head[0], head[1]});
        snakeSet.add(headKey);
        return snake.size();
    }
}