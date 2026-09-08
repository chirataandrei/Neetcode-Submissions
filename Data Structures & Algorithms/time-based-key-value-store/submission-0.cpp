class TimeMap {
public:
    std::unordered_map<std::string, std::vector<std::pair<int, std::string>>> mp;

    TimeMap() {}
    
    void set(std::string key, std::string value, int timestamp) {
        mp[key].emplace_back(timestamp, value);
    }
    
    std::string get(const std::string& key, int timestamp) {
        auto it = mp.find(key);
        if (it == mp.end()) {
            return "";
        }
        const auto& arr = it->second;
        auto vec_it = std::upper_bound(
            arr.begin(), 
            arr.end(), 
            timestamp,
            [](int target, const std::pair<int, std::string>& item) {
                return target < item.first;
            }
        );
        if (vec_it == arr.begin()) {
            return "";
        }
        return std::prev(vec_it)->second;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */