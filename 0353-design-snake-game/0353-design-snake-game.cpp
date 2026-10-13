class SnakeGame {
public:
    deque<pair<int,int>> snake;
    unordered_set<int> snakeSet;
    int headR, headC;
    int width, height;
    vector<vector<int>>& food;
    int foodIndex;
    SnakeGame(int width, int height, vector<vector<int>>& food) : food(food) {
        this->width = width; this->height = height;
        headR = 0; headC = 0;
        snake.push_back({0,0});
        snakeSet.insert(0 * width + 0);
        foodIndex = 0;
    }
    int move(string direction) {
        if (direction == "U") headR--;
        if (direction == "D") headR++;
        if (direction == "L") headC--;
        if (direction == "R") headC++;
        if (headR < 0 || headR >= height || headC < 0 || headC >= width) return -1;
        int headKey = headR * width + headC;
        if (foodIndex < (int)food.size() && headR == food[foodIndex][0] && headC == food[foodIndex][1]) {
            foodIndex++;
        } else {
            auto tail = snake.front(); snake.pop_front();
            snakeSet.erase(tail.first * width + tail.second);
        }
        if (snakeSet.find(headKey) != snakeSet.end()) return -1;
        snake.push_back({headR, headC});
        snakeSet.insert(headKey);
        return snake.size();
    }
};