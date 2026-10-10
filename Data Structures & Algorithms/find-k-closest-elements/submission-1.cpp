class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int right = k, left = 0;

        for (left = 0; right < arr.size(); left++, right++) {
            int curr_len = abs(x - arr[left]);
            if (abs(x - arr[right]) >= curr_len && arr[right] != arr[left]) {
                break;
            }
        }

        vector<int> res(arr.begin() + left, arr.begin() + right);
        return res;
    }
};