class MinStack {
    size_t size;
    stack<int> st;
    stack<int> min_stack;

public:
    MinStack() : size(0) {}
    
    void push(int val) {
        if (size == 0) {
            min_stack.push(val);
        } else {
            min_stack.push(min(val, min_stack.top()));
        }
        st.push(val);
        size++;
    }
    
    void pop() {
        if (size == 0) {
            return;
        }
        min_stack.pop();
        st.pop();
        size--;
    }
    
    int top() {
        if (size == 0) {
            return -1;
        }
        return st.top();
    }
    
    int getMin() {
        if (size == 0) {
            return -1;
        }
        return min_stack.top();
    }
};
