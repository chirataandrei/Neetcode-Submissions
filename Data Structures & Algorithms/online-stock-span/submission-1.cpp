class StockSpanner {
    vector<int> prices;
    stack<int> span;
    size_t size;

public:
    StockSpanner() : size(0) {}
    
    int next(int price) {
        int res;
        
        while (!span.empty() && prices[span.top()] <= price) {
            span.pop();
        }
        
        if (!span.empty()) {
            res = prices.size() - span.top();
        } else {
            res = prices.size() + 1;
        }

        span.push(prices.size());
        prices.push_back(price);
        size++;
        return res;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */