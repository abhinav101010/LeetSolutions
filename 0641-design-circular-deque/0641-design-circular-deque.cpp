class MyCircularDeque {
private:
    vector<int> queue;
    int capacity;
    int size;
    int front;
    int rear;

public:
    MyCircularDeque(int k) {
        queue.assign(k, 0);
        capacity = k;
        size = 0;
        front = 0;
        rear = 0;
    }

    bool insertFront(int value) {
        if (isFull()) return false;
        front = (front - 1 + capacity) % capacity;
        queue[front] = value;
        size++;
        return true;
    }

    bool insertLast(int value) {
        if (isFull()) return false;
        queue[rear] = value;
        rear = (rear + 1) % capacity;
        size++;
        return true;
    }

    bool deleteFront() {
        if (isEmpty()) return false;
        front = (front + 1) % capacity;
        size--;
        return true;
    }

    bool deleteLast() {
        if (isEmpty()) return false;
        rear = (rear - 1 + capacity) % capacity;
        size--;
        return true;
    }

    int getFront() {
        if (isEmpty()) return -1;
        return queue[front];
    }

    int getRear() {
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