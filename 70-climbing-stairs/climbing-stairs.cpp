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
        int prev1 = 1;
        int prev2 = 1;
        
        for(int i = 2;i<=n;i++){
            int curr = prev1 + prev2;
            prev2 = prev1;
            prev1 = curr;
        }

        return prev1;
    }
public:
    int climbStairs(int n) {
        return solveTB(n);
    }
};