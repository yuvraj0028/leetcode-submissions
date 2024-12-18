class Solution {
private:
    int findProfit(int i, bool buy, vector<int>& prices, vector<vector<int > > &dp){
        if(i >= prices.size()) return 0;

        if(dp[i][buy] != -1) return dp[i][buy];

        int profit = 0;

        if(buy){
            int buy_stock = -prices[i] + findProfit(i+1, 0, prices, dp);
            int ignore = findProfit(i+1, 1, prices, dp);
            profit = max(buy_stock, ignore);
        } else {
            int sell_stock = prices[i] + findProfit(i+1, 1, prices, dp);
            int ignore = findProfit(i+1, 0, prices, dp);
            profit = max(sell_stock, ignore);
        }

        return dp[i][buy] = profit;
    }
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int > > dp(n+1, vector<int>(2,-1));
        return findProfit(0,1,prices,dp);
    }
};