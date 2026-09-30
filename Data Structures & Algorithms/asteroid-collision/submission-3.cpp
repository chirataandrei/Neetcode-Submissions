class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        int num = asteroids.size();
        vector<int> res;
        
        for (int i = 0; i < num; i++) {
            if (asteroids[i] > 0) {
                res.push_back(asteroids[i]);
            } else {
                if (!res.empty() && res.back() > 0) {
                    while (!res.empty() && res.back() > 0) {
                        if (res.back() < -asteroids[i]) {
                            res.pop_back();
                        } else {
                            break;
                        }
                    }
                    if (!res.empty() && res.back() == -asteroids[i]) {
                        res.pop_back();
                    } else if (res.empty() == true || (!res.empty() && res.back() < 0)){
                        res.push_back(asteroids[i]);
                    }
                } else {
                    res.push_back(asteroids[i]);
                }
            }
        }

        return res;
    }
};