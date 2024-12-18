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
public:
    int maxProfit(vector<int>& prices) {
        memset(dp, -1, sizeof(dp));
        return solve(0, 1, 2, prices);
    }
};