class Solution {
private:
    int getMinCostRec(vector<int>& cost, int i, vector<int> &dp) {
        if(i>=cost.size()) return 0;

        if(dp[i] != -1) return dp[i];

        int currStep = cost[i] + getMinCostRec(cost, i+1, dp);
        int nextStep = cost[i] + getMinCostRec(cost, i+2, dp);

        return dp[i] = min(currStep, nextStep);
    }
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(n + 1, -1);
        int initialStep = getMinCostRec(cost, 0, dp);

        dp.assign(n+1, -1);
        int nextStep = getMinCostRec(cost, 1, dp);

        return min(initialStep, nextStep);
    }
};