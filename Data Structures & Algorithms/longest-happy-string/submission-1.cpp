class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        string res = "";
        priority_queue<pair<int, char>> freq;
        
        if (a) {
            freq.push({a, 'a'}); 
        }
        if (b) {
            freq.push({b, 'b'});
        }
        if (c) {
            freq.push({c, 'c'});
        }

        pair<int, char> prev = {0, '0'};
        while (!freq.empty()) {
            auto curr = freq.top();
            freq.pop();
            if (curr.first >= prev.first) {
                res.push_back(curr.second);
                if (curr.first >= 2) {
                    res.push_back(curr.second);
                    curr.first--;
                }
                curr.first--;
            } else {
                res.push_back(curr.second);
                curr.first--;
            }
            if (prev.first) {
                freq.push(prev);
            }
            prev = curr;
        }

        return res;
    }
};