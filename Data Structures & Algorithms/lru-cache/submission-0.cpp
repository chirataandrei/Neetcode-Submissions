class LRUCache {
public:
    std::unordered_map<int, std::pair<int, std::list<int>::iterator>> mp;
    std::list<int> l;
    int capacity;

    LRUCache(int capacity) {
        this->capacity = capacity;
    }
    
    int get(int key) {
        auto it = mp.find(key);
        if (it == mp.end()) {
            return -1;
        }
        std::list<int>::iterator node_it = it->second.second;
        l.splice(l.begin(), l, node_it);
        return it->second.first;
    }
    
    void put(int key, int value) {
        auto it = mp.find(key);
        if (it == mp.end()) {
            if (mp.size() == capacity) {
                int lru_key = l.back();
                l.pop_back();
                mp.erase(lru_key);
            }
            l.push_front(key);
            mp.insert({key,{value, l.begin()}});
        } else {
            it->second.first = value;
            l.splice(l.begin(), l, it->second.second);
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */