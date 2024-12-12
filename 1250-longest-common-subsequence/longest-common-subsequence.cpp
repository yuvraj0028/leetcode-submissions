class Solution {
private: 
    int solveSubSeq(int i, int j, string &text1, string &text2, vector<vector<int > > &dp){
        if(i>=text1.size() || j>=text2.size()) return 0;

        if(dp[i][j] != -1) return dp[i][j];

        if(text1[i] == text2[j]){
            return dp[i][j] = 1 + solveSubSeq(i+1, j+1, text1, text2, dp);
        } else {
            int takeI = solveSubSeq(i+1, j, text1, text2, dp);
            int takeJ = solveSubSeq(i, j+1, text1, text2, dp);
            int takeBoth = solveSubSeq(i+1, j+1, text1, text2, dp);

            return dp[i][j] = max(takeI,max(takeJ,takeBoth));
        }
    }
public:
    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int > > dp(text1.size(), vector<int>(text2.size()+1,-1));
        return solveSubSeq(0, 0, text1, text2, dp);
    }
};