class Solution {
private:
    int solve(string &text1, string &text2, int i, int j, vector<vector<int > > &dp){
        if(i>=text1.size() || j>=text2.size()){
            return 0;
        }

        if(dp[i][j] != -1) return dp[i][j];

        if(text1[i] == text2[j]){
            return dp[i][j] = 1 + solve(text1, text2, i+1, j+1, dp);
        } else {
            int take1 = solve(text1, text2, i+1, j, dp);
            int take2 = solve(text1, text2, i, j+1, dp);
            int takeBoth = solve(text1, text2, i+1, j+1, dp);

            return dp[i][j] = max({take1, take2, takeBoth});
        }
    }

public:
    int longestPalindromeSubseq(string s) {
        string t(s.rbegin(), s.rend());
        vector<vector<int > > dp(s.size()+1,vector<int>(t.size()+1,-1));
        return solve(s, t, 0, 0, dp);
    }
};