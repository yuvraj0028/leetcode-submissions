class Solution {
private:
    vector<int> dp;
    int MOD = 1e9 + 7;

    int solve(int n) {
        if (n == 0) return 1;
        if (n == 1) return 1;
        if (n == 2) return 2;

        if(dp[n] != -1) return dp[n];

        int domino = (2 * solve(n-1)) % MOD;
        int tromino = solve(n - 3) % MOD;

        return dp[n] = (domino % MOD + tromino % MOD) % MOD;
    }
public:
    int numTilings(int n) {
        dp.resize(n+1,-1);
        return solve(n);
    }
};
