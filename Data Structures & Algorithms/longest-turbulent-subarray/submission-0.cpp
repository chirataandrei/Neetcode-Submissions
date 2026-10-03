class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        int curr_max = 1, global_max = 0;
        
        if (arr.size() == 1) {
            return 1;
        } else if (arr.size() == 2) {
            if (arr[0] == arr[1]) {
                return 1;
            }
            return 2;
        }

        for (int i = 1; i < arr.size() - 1; i++) {
            if ((arr[i] > arr[i - 1] && arr[i] > arr[i + 1]) || (arr[i] < arr[i - 1] && arr[i] < arr[i + 1])) {
                curr_max = max(curr_max + 1, 3);
            } else {
                if (arr[i] != arr[i - 1] || arr[i] != arr[i + 1]) {
                    curr_max = 2;
                } else {
                    curr_max = 1;
                }
            }

            global_max = max(global_max, curr_max);
        }

        return global_max;
    }
};