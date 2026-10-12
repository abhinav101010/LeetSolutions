class MyCircularDeque {
    private int[] queue;
    private int capacity;
    private int size;
    private int front;
    private int rear;

    public MyCircularDeque(int k) {
        queue = new int[k];
        capacity = k;
        size = 0;
        front = 0;
        rear = 0;
    }

    public boolean insertFront(int value) {
        if (isFull()) return false;
        front = (front - 1 + capacity) % capacity;
        queue[front] = value;
        size++;
        return true;
    }

    public boolean insertLast(int value) {
        if (isFull()) return false;
        queue[rear] = value;
        rear = (rear + 1) % capacity;
        size++;
        return true;
    }

    public boolean deleteFront() {
        if (isEmpty()) return false;
        front = (front + 1) % capacity;
        size--;
        return true;
    }

    public boolean deleteLast() {
        if (isEmpty()) return false;
        rear = (rear - 1 + capacity) % capacity;
        size--;
        return true;
    }

    public int getFront() {
        if (isEmpty()) return -1;
        return queue[front];
    }

    public int getRear() {
        if (isEmpty()) return -1;
        return queue[(rear - 1 + capacity) % capacity];
    }

    public boolean isEmpty() {
        return size == 0;
    }

    public boolean isFull() {
        return size == capacity;
    }
}