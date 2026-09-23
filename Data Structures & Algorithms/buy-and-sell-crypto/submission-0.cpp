class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy = prices[0];

        int max_profit = 0;
        
        for(int i = 1; i < prices.size(); ++i) {
            if(prices[i - 1] < buy) buy = prices[i - 1];

            max_profit = max(max_profit, prices[i] - buy);
        }

        return max_profit;
    }
};
