class MyCircularQueue {
private:
    list<int> ring_buff;
    int cap, size;

public:
    MyCircularQueue(int k): cap(k), size(0) {}
    
    bool enQueue(int value) {
        if (isFull()) {
            return false;
        }

        ring_buff.push_back(value);

        size++;
        return true;
    }
    
    bool deQueue() {
        if (isEmpty()) {
            return false;
        }

        ring_buff.pop_front();

        size--;
        return true;
    }
    
    int Front() {
        if (isEmpty()) {
            return -1;
        }

        return ring_buff.front();
    }
    
    int Rear() {
        if (isEmpty()) {
            return -1;
        }

        return ring_buff.back();
    }
    
    bool isEmpty() {
        return size == 0;
    }
    
    bool isFull() {
        return cap == size;
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