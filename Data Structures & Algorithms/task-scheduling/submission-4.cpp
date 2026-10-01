class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> freq(26, 0);
        int max_freq = 0;
        int count_max_freq = 0;

        for (char c : tasks) {
            freq[c - 'A']++;
            max_freq = max(max_freq, freq[c - 'A']);
        }
        
        for (int count : freq) {
            if (count == max_freq) {
                count_max_freq++;
            }
        }

        int ans = max((max_freq - 1) * (n + 1) + count_max_freq, (int)tasks.size());

        return ans;
    }
};
