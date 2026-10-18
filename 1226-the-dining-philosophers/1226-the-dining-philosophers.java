class DiningPhilosophers {
    private final ReentrantLock[] forks = new ReentrantLock[5];
    
    public DiningPhilosophers() {
        for (int i = 0; i < 5; i++) {
            forks[i] = new ReentrantLock();
        }
    }
    
    public void wantsToEat(int philosopher,
                           Runnable pickLeftFork,
                           Runnable pickRightFork,
                           Runnable eat,
                           Runnable putLeftFork,
                           Runnable putRightFork) throws InterruptedException {
        int left = philosopher;
        int right = (philosopher + 1) % 5;
        if (philosopher % 2 == 0) {
            forks[left].lock();
            forks[right].lock();
        } else {
            forks[right].lock();
            forks[left].lock();
        }
        pickLeftFork.run();
        pickRightFork.run();
        eat.run();
        putLeftFork.run();
        putRightFork.run();
        if (philosopher % 2 == 0) {
            forks[right].unlock();
            forks[left].unlock();
        } else {
            forks[left].unlock();
            forks[right].unlock();
        }
    }
}
