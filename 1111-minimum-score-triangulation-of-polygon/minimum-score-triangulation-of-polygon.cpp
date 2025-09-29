class Solution {
public:
    int solve(vector<int>& v, int i,int j,vector<vector<int > > &dp){
        if(i+1 == j) return 0;

        if(dp[i][j] != -1) return dp[i][j];

        int ans = INT_MAX;

        for(int k = i+1;k<j;k++){
            ans = min(ans, (v[i] * v[j] * v[k]) + solve(v,i,k,dp) + solve(v,k,j,dp));
        }

        return dp[i][j] = ans;
    }

    int minScoreTriangulation(vector<int>& values) {
        int i = 0;
        int j = values.size() - 1;

        vector<vector<int > > dp(values.size(),vector<int>(values.size(),-1));

        return solve(values,i,j,dp);
    }
};