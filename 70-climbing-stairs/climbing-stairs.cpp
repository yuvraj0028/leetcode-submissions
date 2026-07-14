class Solution {
private:
    int climbStairsHelperRec(int n, vector<int> &dp) {
        if(n<0) return 0;

        if(n==0) return 1;

        if(dp[n] != -1) return dp[n];
        
        return dp[n] = climbStairsHelperRec(n-1, dp) + climbStairsHelperRec(n-2, dp);
    }

    int climbStairsHelperTab(int n) {
        vector<int> dp(n+1, 0);

        dp[0] = 1;
        dp[1] = 1;

        for(int i = 2; i<=n; i++) {
            dp[i] = dp[i-1] + dp[i-2];
        }

        return dp[n];
    }
public:
    int climbStairs(int n) {
        // vector<int> dp(n+1, -1);
        // return climbStairsHelper(n, dp);

        return climbStairsHelperTab(n);
    }
};