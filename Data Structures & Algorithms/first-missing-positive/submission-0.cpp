class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        for (int i = 0; i < nums.size(); i++) {
            while (nums[i] > 0 && nums[i] <= nums.size() && nums[i] != nums[nums[i] - 1]) {
                swap(nums[i], nums[nums[i] - 1]);
            }
        }
        int res = nums.size() + 1;
        for (int i = 0; i < nums.size(); i++) {
            if (i + 1 != nums[i]) {
                res = i + 1;
                break;
            }
        }
        return res;
    }
};