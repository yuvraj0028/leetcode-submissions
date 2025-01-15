class Solution {
private:
    int solve(int n, vector<int> &dp){
        if(n == 0 || n == 1) return 1;

        if(dp[n] != -1) return dp[n];

        int oneStep = solve(n-1,dp);
        int twoSteps = solve(n-2,dp);

        return dp[n] = oneStep + twoSteps;
    }

    int solveTB(int n){
        vector<int> dp(n+1,0);

        dp[0] = 1;
        dp[1] = 1;
        
        for(int i = 2;i<=n;i++){
            int oneStep = dp[i-1];
            int twoSteps = dp[i-2];

            dp[i] = oneStep + twoSteps;
        }

        return dp[n];
    }
public:
    int climbStairs(int n) {
        return solveTB(n);
    }
};