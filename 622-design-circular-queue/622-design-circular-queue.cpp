class MyCircularQueue {
public:
    
    int MAX_LIMIT;
    int front;
    int rare;
    int Q[3001];
    
    MyCircularQueue(int k) {
        MAX_LIMIT = k;
        front = 0;
        rare = 0;
    }
    
    bool enQueue(int value) {
        if(rare == MAX_LIMIT) return false;
        Q[rare++] = value;
        return true;
    }
    
    bool deQueue() {
        if(rare == front) {
            return false;
        }
        front++;
        MAX_LIMIT++;
        return true;
    }
    
    int Front() {
        if (front == rare) return -1;
        return Q[front];
    }
    
    int Rear() {
        if (front == rare) return -1;
        return Q[rare-1];
    }
    
    bool isEmpty() {
        return rare == front;
    }
    
    bool isFull() {
        return rare == MAX_LIMIT;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */