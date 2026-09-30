class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int num = temperatures.size();
        vector<int> res(num, 0);
        stack<pair<int, int>> st;

        st.push({temperatures[num - 1], num - 1});
        for (int i = num - 2; i >= 0; i--) {
            if (temperatures[i] < st.top().first) {
                res[i] = st.top().second - i;
            } else {
                while (!st.empty() && temperatures[i] >= st.top().first) {
                    st.pop();
                }
                if (!st.empty()) {
                    res[i] = st.top().second - i;
                }
            }
            st.push({temperatures[i], i});
        }

        return res;
    }
};
