from collections import deque

class SnakeGame:
    def __init__(self, width: int, height: int, food: List[List[int]]):
        self.width = width
        self.height = height
        self.food = food
        self.food_index = 0
        self.snake = deque([(0, 0)])
        self.snake_set = set([(0, 0)])
        self.score = 0
        self.dirs = {'U': (-1, 0), 'D': (1, 0), 'L': (0, -1), 'R': (0, 1)}
    
    def move(self, direction: str) -> int:
        head = self.snake[-1]
        dr, dc = self.dirs[direction]
        new_head = (head[0] + dr, head[1] + dc)
        if new_head[0] < 0 or new_head[0] >= self.height or new_head[1] < 0 or new_head[1] >= self.width:
            return -1
        if self.food_index < len(self.food) and new_head[0] == self.food[self.food_index][0] and new_head[1] == self.food[self.food_index][1]:
            self.score += 1
            self.food_index += 1
        else:
            tail = self.snake.popleft()
            self.snake_set.discard(tail)
        if new_head in self.snake_set:
            return -1
        self.snake.append(new_head)
        self.snake_set.add(new_head)
        return self.score