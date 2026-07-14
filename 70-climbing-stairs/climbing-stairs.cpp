class Solution {
private:
    int climbStairsHelperRec(int n, vector<int> &dp) {
        if(n<0) return 0;

        if(n==0) return 1;

        if(dp[n] != -1) return dp[n];
        
        return dp[n] = climbStairsHelperRec(n-1, dp) + climbStairsHelperRec(n-2, dp);
    }

    int climbStairsHelperTab(int n) {
        if(n<=1) return 1;

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
        // recursive -> T.C=O(N) & S.C=O(N)
        // vector<int> dp(n+1, -1);
        // return climbStairsHelper(n, dp);

        // Tabular -> T.C=O(N) & S.C=O(N)
        // return climbStairsHelperTab(n);

        // Tabular Oprimized -> T.C=O(N) & S.C=O(1)

        if(n<=1) return 1;

        int prev = 1;
        int prev2 = 1;
        int curr = 0;

        for(int i = 2; i<=n; i++) {
            curr = prev + prev2;

            prev2 = prev;
            prev = curr;
        }

        return curr;
    }
};