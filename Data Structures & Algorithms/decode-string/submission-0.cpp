class Solution {
public:
    string decodeString(string s) {
        stack<int> count_st;
        stack<string> string_st;
        string curr_str = "";
        int k = 0;

        for (char c : s) {
            if (isdigit(c)) {
                k = k * 10 + (c - '0');
            } else if (c == '[') {
                count_st.push(k);
                string_st.push(curr_str);
                curr_str = "";
                k = 0;
            } else if (c == ']') {
                int curr_num = count_st.top();
                count_st.pop();
                string prev_str = string_st.top();
                string_st.pop();
                while (curr_num--) {
                    prev_str += curr_str;
                }
                curr_str = move(prev_str);
            } else {
                curr_str += c;
            }
        }

        return curr_str;
    }
};