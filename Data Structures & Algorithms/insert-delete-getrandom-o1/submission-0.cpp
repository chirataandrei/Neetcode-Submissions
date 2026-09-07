class RandomizedSet {
public:
    std::unordered_map<int, int> mp;
    std::mt19937 gen;
    std::vector<int> v;

    RandomizedSet() : gen(std::random_device{}()){}
    
    bool insert(int val) {
        std::unordered_map<int, int>::iterator it = mp.find(val);
        if (it != mp.end()) {
            return false;
        }
        mp.insert({val, v.size()});
        v.push_back(val);
        return true;   
    }
    
    bool remove(int val) {
        std::unordered_map<int, int>::iterator it = mp.find(val);
        if (it == mp.end()) {
            return false;
        }
        int idx = it->second;
        int last = v.back();
        v[idx] = last;
        mp[last] = idx;
        v.pop_back();
        mp.erase(val);
        return true;
    }
    
    int getRandom() {
        std::uniform_int_distribution<int> dist(0, v.size() - 1);
        int rand_idx = dist(gen);
        return v[rand_idx];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */