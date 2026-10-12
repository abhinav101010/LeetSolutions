class MyCircularQueue {
private:
    vector<int> queue;
    int capacity;
    int size;
    int front;
    int rear;

public:
    MyCircularQueue(int k) {
        queue.assign(k, 0);
        capacity = k;
        size = 0;
        front = 0;
        rear = 0;
    }

    bool enQueue(int value) {
        if (isFull()) return false;
        queue[rear] = value;
        rear = (rear + 1) % capacity;
        size++;
        return true;
    }

    bool deQueue() {
        if (isEmpty()) return false;
        front = (front + 1) % capacity;
        size--;
        return true;
    }

    int Front() {
        if (isEmpty()) return -1;
        return queue[front];
    }

    int Rear() {
        if (isEmpty()) return -1;
        return queue[(rear - 1 + capacity) % capacity];
    }

    bool isEmpty() {
        return size == 0;
    }

    bool isFull() {
        return size == capacity;
    }
};