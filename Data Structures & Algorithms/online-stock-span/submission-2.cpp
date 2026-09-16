class StockSpanner {
public:
    StockSpanner() {
    }
    
    int next(int price) {
        int span = 1;

        while(!previousPrices.empty() && previousPrices.top().first <= price) {
            span += previousPrices.top().second;
            previousPrices.pop();
        }
        previousPrices.push({price, span});
        return span;
    }
private:
    stack<pair<int, int>> previousPrices;
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */