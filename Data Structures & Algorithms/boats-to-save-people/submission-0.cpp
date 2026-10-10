class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(), people.end());

        int min_boats = 0, right = people.size() - 1, left = 0;
        while (left < right) {
            if (people[right] + people[left] <= limit) {
                right--, left++, min_boats++;
            } else {
                right--, min_boats++;
            }
        }

        if (left == right) {
            min_boats++;
        }

        return min_boats;
    }
};