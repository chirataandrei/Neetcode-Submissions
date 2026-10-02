class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        vector<int> diff(1001, 0);
        int curr_cap = 0;

        for (const auto& t : trips) {
            diff[t[1]] += t[0];
            diff[t[2]] -= t[0];
        }

        for (int i = 0; i <= 1000; i++) {
            curr_cap += diff[i];
            if (curr_cap > capacity) {
                return false;
            }
        }
        
        return true;
    }
        
};