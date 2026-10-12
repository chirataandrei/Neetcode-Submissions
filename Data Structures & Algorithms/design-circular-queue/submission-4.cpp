static const auto _ = []() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    return nullptr;
}();

class MyCircularQueue {
private:
    vector<int> ring_buff;
    int cap, size;
    int start, end;

public:
    MyCircularQueue(int k): cap(k), size(0), start(0), end(-1), ring_buff(k) {}
    
    bool enQueue(int value) {
        if (isFull()) {
            return false;
        }

        if (++end == cap) end = 0;

        ring_buff[end] = value;
 
        size++;
        return true;
    }
    
    bool deQueue() {
        if (isEmpty()) {
            return false;
        }
        
        if (++start == cap) start = 0;

        size--;
        return true;
    }
    
    int Front() {
        if (isEmpty()) {
            return -1;
        }

        return ring_buff[start];
    }
    
    int Rear() {
        if (isEmpty()) {
            return -1;
        }

        return ring_buff[end];
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