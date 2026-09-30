class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int num = temperatures.size();
        vector<int> res(num, 0);
        stack<int> st;

        st.push(num - 1);
        for (int i = num - 2; i >= 0; i--) {
            if (temperatures[i] < temperatures[st.top()]) {
                res[i] = st.top() - i;
            } else {
                while (!st.empty() && temperatures[i] >= temperatures[st.top()]) {
                    st.pop();
                }
                if (!st.empty()) {
                    res[i] = st.top() - i;
                }
            }
            st.push(i);
        }

        return res;
    }
};
