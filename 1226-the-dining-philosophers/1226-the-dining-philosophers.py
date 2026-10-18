import threading

class DiningPhilosophers:
    def __init__(self):
        self.forks = [threading.Lock() for _ in range(5)]

    def wantsToEat(self, philosopher: int, pickLeftFork: 'Callable[[], None]', pickRightFork: 'Callable[[], None]', eat: 'Callable[[], None]', putLeftFork: 'Callable[[], None]', putRightFork: 'Callable[[], None]') -> None:
        left = philosopher
        right = (philosopher + 1) % 5
        if philosopher % 2 == 0:
            self.forks[left].acquire()
            self.forks[right].acquire()
        else:
            self.forks[right].acquire()
            self.forks[left].acquire()
        pickLeftFork()
        pickRightFork()
        eat()
        putLeftFork()
        putRightFork()
        if philosopher % 2 == 0:
            self.forks[right].release()
            self.forks[left].release()
        else:
            self.forks[left].release()
            self.forks[right].release()
