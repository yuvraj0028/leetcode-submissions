class Solution {
private:
    int findProfit(int i, int buy, vector<int>& prices, vector<vector<int > > &dp){
        if(i>=prices.size()) return 0;

        if(dp[i][buy]!=-1) return dp[i][buy];

        int profit = 0;

        if(buy){
            int buyStock = -prices[i] + findProfit(i+1, 0, prices, dp);
            int ignore = findProfit(i+1, 1, prices, dp);
            profit = max(buyStock, ignore);
        } else {
            int sellStock = prices[i] + findProfit(i+2, 1, prices, dp);
            int ignore = findProfit(i+1, 0, prices, dp);
            profit = max(sellStock, ignore);
        }

        return dp[i][buy] = profit;
    }

    int findProfitTabulation(vector<int>& prices){
        int n = prices.size();
        vector<vector<int > > dp(n+2, vector<int>(2));

        for(int i = n-1; i>=0; i--){
            for(int buy = 0; buy<2; buy++){
                int profit = 0;

                if(buy){
                    int buyStock = -prices[i] + dp[i+1][0];
                    int ignore = dp[i+1][1];
                    profit = max(buyStock, ignore);
                } else {
                    int sellStock = prices[i] + dp[i+2][1];
                    int ignore = dp[i+1][0];
                    profit = max(sellStock, ignore);
                }

                dp[i][buy] = profit;
            }
        }

        return dp[0][1];
    }

    int findProfitOptimized(vector<int>& prices){
        int n = prices.size();
        vector<int> curr(2), next(2), next_2(2);

        for(int i = n-1; i>=0; i--){
            for(int buy = 0; buy<2; buy++){
                int profit = 0;

                if(buy){
                    int buyStock = -prices[i] + next[0];
                    int ignore = next[1];
                    profit = max(buyStock, ignore);
                } else {
                    int sellStock = prices[i] + next_2[1];
                    int ignore = next[0];
                    profit = max(sellStock, ignore);
                }

                curr[buy] = profit;
            }
            next_2 = next;
            next = curr;
        }

        return next[1];
    }

public:
    int maxProfit(vector<int>& prices) {
        // int n = prices.size();
        // vector<vector<int > > dp(n+1, vector<int>(2,-1));
        // return findProfit(0, 1, prices, dp);
        // return findProfitTabulation(prices);
        return findProfitOptimized(prices);
    }
};