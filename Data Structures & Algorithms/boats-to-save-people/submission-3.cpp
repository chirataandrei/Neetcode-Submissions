class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        vector<int> freq(limit + 1, 0);

        for (int p : people) {
            freq[p]++;
        }

        int left = 0, right = limit, min_boats = 0;
        while (left < right) {
            while (left < right && freq[left] == 0) {
                left++;
            }
            while (left < right && freq[right] == 0) {
                right--;
            }

            if (right <= left) {
                break;
            }

            if (right + left <= limit) {
                freq[left]--, freq[right]--, min_boats++;
            } else {
                freq[right]--, min_boats++;
            }
        }

        while (left == right && freq[left] > 0) {
            if (left + right <= limit) {
                freq[left] -= 2;
            } else {
                freq[left]--;
            }
            min_boats++;
        }

        return min_boats;
    }
};