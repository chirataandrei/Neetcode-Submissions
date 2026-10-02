class Solution {
private:
    struct Passengers {
        int cap, from, to;
        bool operator<(const Passengers& other) const {
            return from < other.from;
        }
        bool operator>(const Passengers& other) const {
            return to > other.to;
        }
    };

public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        vector<Passengers> sorted_trips;
        priority_queue<Passengers, vector<Passengers>, greater<Passengers>> car;
        int max_to = 0;
        for (const auto& t :trips) {
            sorted_trips.emplace_back(t[0], t[1], t[2]);
            max_to = max(max_to, t[2]);
        }
        sort(sorted_trips.begin(), sorted_trips.end());

        bool is_ok = true;
        int curr_capacity = 0;
        int idx = 0, sz = trips.size();
        for (int time = 0; time <= max_to; time++) {
            while (!car.empty() && car.top().to == time) {
                curr_capacity -= car.top().cap;
                car.pop();
            }
            while (idx < sz && sorted_trips[idx].from == time) {
                car.push(sorted_trips[idx]);
                curr_capacity += sorted_trips[idx].cap;
                idx++;
            }
            if (curr_capacity > capacity) {
                is_ok = false;
                break;
            }
        }

        return is_ok;
    }
        
};