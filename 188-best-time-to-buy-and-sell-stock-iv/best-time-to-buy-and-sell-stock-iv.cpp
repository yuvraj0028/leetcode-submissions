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

public:
    int maxProfit(int k, vector<int>& prices) {
        memset(dp, -1, sizeof(dp));
        return findProfit(0, 1, k, prices);
    }
};