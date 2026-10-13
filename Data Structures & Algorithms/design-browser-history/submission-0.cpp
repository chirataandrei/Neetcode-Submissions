class BrowserHistory {
private:
    vector<string> history;
    int curr_pos;

public:
    BrowserHistory(string homepage) {  
        history.push_back(homepage);
        curr_pos = 0;
    }
    
    void visit(string url) {
        if (curr_pos + 1 != history.size()) {
            history.resize(curr_pos + 1);
        }
        history.push_back(url);
        curr_pos = history.size() - 1;
    }
    
    string back(int steps) {
        int idx = (curr_pos - steps < 0) ? 0 : curr_pos - steps;
        curr_pos = idx;
        return history[idx]; 
    }
    
    string forward(int steps) {
        int idx = (curr_pos + steps < history.size()) ? curr_pos + steps : history.size() - 1;
        curr_pos = idx;
        return history[idx];
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */