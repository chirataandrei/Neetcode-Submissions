class Solution {
public:
    bool canJump(vector<int>& nums) {
        int max_dist = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (max_dist < i) {
                return false;
            }
            max_dist = max(max_dist, i + nums[i]);
        }

        return true;
    }
};
