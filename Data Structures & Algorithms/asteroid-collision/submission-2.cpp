class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        int num = asteroids.size();
        vector<int> st;
        vector<int> res;
        
        for (int i = 0; i < num; i++) {
            if (asteroids[i] > 0) {
                st.push_back(asteroids[i]);
            } else {
                if (!st.empty()) {
                    while (!st.empty() && st.back() < -asteroids[i]) {
                        st.pop_back();
                    }
                    if (!st.empty() && st.back() == -asteroids[i]) {
                        st.pop_back();
                    } else if (st.empty()) {
                        res.push_back(asteroids[i]);
                    }
                } else {
                    res.push_back(asteroids[i]);
                }
            }
        }

        if (!st.empty()) {
            res.insert(res.end(), st.begin(), st.end());   
        }

        return res;
    }
};