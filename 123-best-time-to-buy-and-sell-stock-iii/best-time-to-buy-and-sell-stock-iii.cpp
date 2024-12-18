class Solution {
    int dp[100001][3][3];
private:
    int solve(int i, int buy, int limit, vector<int>& prices){
        if(i>=prices.size()) return 0;

        if(limit <= 0) return 0;

        if(dp[i][buy][limit] != -1) return dp[i][buy][limit];

        int profit = 0;

        if(buy){
            int buy_stock = -prices[i] + solve(i+1, 0, limit, prices);
            int ignore = solve(i+1, 1, limit, prices);
            profit = max(buy_stock, ignore);
        } else {
            int sell_stock = prices[i] + solve(i+1, 1, limit - 1, prices);
            int ignore = solve(i+1, 0, limit, prices);
            profit = max(sell_stock, ignore);
        }

        return dp[i][buy][limit] = profit;
    }

    int solveTab(vector<int>& prices){
        int n = prices.size();

        for(int i = n-1; i>=0 ;i--){
            for(int buy = 0; buy<2; buy++){
                for(int limit = 1; limit<3; limit++){
                    int profit = 0;

                    if(buy){
                        int buy_stock = -prices[i] + dp[i+1][0][limit];
                        int ignore = dp[i+1][1][limit];
                        profit = max(buy_stock, ignore);
                    } else {
                        int sell_stock = prices[i] + dp[i+1][1][limit-1];
                        int ignore = dp[i+1][0][limit];
                        profit = max(sell_stock, ignore);
                    }

                    dp[i][buy][limit] = profit;
                }
            }
        }

        return dp[0][1][2];
    }

    int solveTabOptimized(vector<int>& prices){
        int n = prices.size();

        vector<vector<int > > curr(2, vector<int> (3));
        vector<vector<int > > next(2, vector<int> (3));

        for(int i = n-1; i>=0; i--){
            for(int buy = 0; buy<2; buy++){
                for(int limit = 1; limit<3; limit++){
                    int profit = 0;

                    if(buy){
                        int buy_stock = -prices[i] + next[0][limit];
                        int ignore = next[1][limit];
                        profit = max(buy_stock, ignore);
                    } else {
                        int sell_stock = prices[i] + next[1][limit-1];
                        int ignore = next[0][limit];
                        profit = max(sell_stock, ignore);
                    }

                    curr[buy][limit] = profit;
                }
            }

            next = curr;
        }

        return next[1][2];
    }
public:
    int maxProfit(vector<int>& prices) {
        // memset(dp, -1, sizeof(dp));
        return solveTabOptimized(prices);
    }
};