class Solution {
private:
    int dp[1001][2][101];
    int findProfit(int i, int buy, int k, vector<int>& prices){
        if(i>=prices.size()) return 0;

        if(k<=0) return 0;

        if(dp[i][buy][k] != -1) return dp[i][buy][k];

        int profit = 0;

        if(buy){
            int buyStock = -prices[i] + findProfit(i+1, 0, k, prices);
            int ignore = findProfit(i+1, 1, k, prices);
            profit = max(buyStock, ignore);
        } else {
            int sellStock = prices[i] + findProfit(i+1, 1, k-1, prices);
            int ignore = findProfit(i+1, 0, k, prices);
            profit = max(sellStock, ignore);
        }

        return dp[i][buy][k] = profit;
    }

    int findProfitTabulation(int k, vector<int>& prices){
        int n = prices.size();

        for(int i = n-1; i>=0; i--){
            for(int buy = 0; buy< 2; buy++){
                for(int limit = 1 ; limit <= k; limit++){
                    int profit = 0;

                    if(buy){
                        int buyStock = -prices[i] + dp[i+1][0][limit];
                        int ignore = dp[i+1][1][limit];
                        profit = max(buyStock, ignore);
                    } else {
                        int sellStock = prices[i] + dp[i+1][1][limit-1];
                        int ignore = dp[i+1][0][limit];
                        profit = max(sellStock, ignore);
                    }

                    dp[i][buy][limit] = profit;
                }
            }
        }

        return dp[0][1][k];
    }

public:
    int maxProfit(int k, vector<int>& prices) {
        memset(dp, 0, sizeof(dp));
        return findProfitTabulation(k, prices);
    }
};