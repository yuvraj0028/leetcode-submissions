class Solution {
private:
    int getMinCostRec(vector<int>& cost, int i, vector<int> &dp) {
        // Cast cost.size() to int to prevent -1 from turning into UINT_MAX
        if (i >= (int)cost.size()) return 0;

        if(dp[i+1] != -1) return dp[i+1];

        int currCost = i == -1 ? 0 : cost[i];

        int currStep = getMinCostRec(cost, i+1, dp);
        int nextStep = getMinCostRec(cost, i+2, dp);

        return dp[i+1] = currCost + min(currStep, nextStep);
    }

    int getMinCostTab(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(n+1, 0);

        dp[0] = 0;
        dp[1] = 0;

        for(int i = 2; i<=n; i++) {
            int step1 = dp[i-1] + cost[i-1]; 
            int step2 = dp[i-2] + cost[i-2];
        
            dp[i] = min(step1, step2);
        }

        return dp[n];
    }

public:
    int minCostClimbingStairs(vector<int>& cost) {
        // recursive -> T.C - O(N), S.C - O(N)
        // int n = cost.size();
        // vector<int> dp(n + 1, -1);
        // int initialStep = getMinCostRec(cost, -1, dp);

        // return initialStep;

        // Tabular -> T.C - O(N), S.C - O(N)
        return getMinCostTab(cost);

    }
};