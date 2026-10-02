class Solution {
public:
    string reorganizeString(string s) {
        string res = "";
        vector<int> freq(26, 0);
        pair<int, char> max_freq = {0, 'a'};

        for (const auto& c : s) {
            freq[c - 'a']++;
            if (freq[c - 'a'] > max_freq.first) {
                max_freq = {freq[c - 'a'], c};
            }
        }
        
        if (max_freq.first > (s.size() + 1) / 2) {
            return res;
        }

        res.resize(s.size());

        int idx = 0;
        while (freq[max_freq.second - 'a']--) {
            res[idx] = max_freq.second;
            idx += 2;
        }

        if (idx >= s.size()) {
            idx = 1;
        }

        for (int i = 0; i < 26; i++) {
            while (freq[i]-- > 0) {
                res[idx] = i + 'a';
                idx = (idx + 2 < s.size()) ? idx + 2 : 1;
            }
        }

        return res;
    }
};