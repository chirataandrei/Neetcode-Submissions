class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int sz = nums.size();
        vector<int> res;
        res.resize(sz);

        k %= nums.size();

        for (int i = 0 ; i < sz; i++) {
            res[i] = nums[(sz - k + i) % sz];
        }

        nums = std::move(res);
    }
};