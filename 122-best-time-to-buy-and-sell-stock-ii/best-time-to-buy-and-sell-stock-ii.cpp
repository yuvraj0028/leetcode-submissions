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

    int findProfitTabulation(vector<int> &prices){
        int n = prices.size();

        vector<int> curr(2), next(2);

        for(int i = n-1; i>=0; i--){
            for(int j = 1;j >= 0; j--){
                int profit = 0;

                if(j){
                    int buy_stock = -prices[i] + next[0];
                    int ignore = next[1];
                    profit = max(buy_stock, ignore);
                } else {
                    int sell_stock = prices[i] + next[1];
                    int ignore = curr[0];
                    profit = max(sell_stock, ignore);
                }

                curr[j] = profit;
            }

            next = curr;
        }

        return next[1];
    }
public:
    int maxProfit(vector<int>& prices) {
        // int n = prices.size();
        // vector<vector<int > > dp(n+1, vector<int>(2,-1));
        return findProfitTabulation(prices);
    }
};