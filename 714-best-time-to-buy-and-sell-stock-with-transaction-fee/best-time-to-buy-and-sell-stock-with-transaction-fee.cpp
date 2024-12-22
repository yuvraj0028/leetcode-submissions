class Solution {

private:
    int findProfit(int i, int buy, vector<int>& prices, int fee, vector<vector<int > > &dp){
        if(i>=prices.size()) return 0;

        if(dp[i][buy]!=-1) return dp[i][buy];

        int profit = 0;

        if(buy){
            int buyStock = -prices[i] + findProfit(i+1, 0, prices, fee, dp);
            int ignore = findProfit(i+1, 1, prices, fee, dp);
            profit = max(buyStock, ignore);
        } else {
            int sellStock = prices[i] + findProfit(i+1, 1, prices, fee, dp) - fee;
            int ignore = findProfit(i+1, 0, prices, fee, dp);
            profit = max(sellStock, ignore);
        }

        return dp[i][buy] = profit;
    }

    int findProfitTabulation(vector<int>& prices, int fee){
        int n = prices.size();
        vector<vector<int > > dp(n+1, vector<int>(2));

        for(int i = n-1; i>=0; i--){
            for(int buy = 0; buy<2; buy++){
                int profit = 0;
                if(buy){
                    int buyStock = -prices[i] + dp[i+1][0];
                    int ignore = dp[i+1][1];
                    profit = max(buyStock, ignore);
                } else {
                    int sellStock = prices[i] + dp[i+1][1] - fee;
                    int ignore = dp[i+1][0];
                    profit = max(sellStock, ignore);
                }

                dp[i][buy] = profit;
            }
        }

        return dp[0][1];
    }

public:
    int maxProfit(vector<int>& prices, int fee) {
        // int n = prices.size();
        // vector<vector<int > > dp(n, vector<int>(2,-1));
        // return findProfit(0, 1, prices, fee, dp);
        return findProfitTabulation(prices, fee);
    }
};