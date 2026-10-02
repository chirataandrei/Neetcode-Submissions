class Solution {
public:
    string reorganizeString(string s) {
        vector<int> freq(26, 0);
        string res = "";
        priority_queue<pair<int, char>> pq;

        for (const auto& c : s) {
            freq[c - 'a']++;
        }

        for (int i = 0; i < 26; i++) {
            if (freq[i]) {
                pq.push({freq[i], i + 'a'});
            }
        }

        if (pq.top().first > (s.size() + 1) / 2) {
            return res;
        }

        while (!pq.empty()) {
            auto curr = pq.top();
            pq.pop();
            res.push_back(curr.second);
            curr.first--;
            if (!pq.empty()) {
                auto next = pq.top();
                pq.pop();
                res.push_back(next.second);
                next.first--;
                if (next.first) {
                    pq.push(next);
                }
            }
            if (curr.first) {
                pq.push(curr);
            }
        }

        return res;
    }
};