class Solution {
private:
    vector<vector<int > > dp;
    int solve(int row, int col, int i, int j){
        if(i>=row || j>=col) return 0;

        if(dp[i][j] != -1) return dp[i][j];

        if(i==row-1 && j==col-1) return dp[i][j] = 1;

        int down = solve(row, col, i+1, j);
        int right = solve(row, col, i, j+1);

        return dp[i][j] = down + right;
    }
public:
    int uniquePaths(int m, int n) {
        dp.resize(m, vector<int> (n,-1));
        return solve(m,n,0,0);
    }
};