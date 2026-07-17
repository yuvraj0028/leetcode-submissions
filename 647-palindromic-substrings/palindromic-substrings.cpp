class Solution {
private:
    int checkPalindromeRec(string s, int i, int j, vector<vector<int > > &dp) {
        if(i>=j) return true;

        if(dp[i][j] != -1) return dp[i][j];

        if(s[i] == s[j]) return dp[i][j] = checkPalindromeRec(s, i+1, j-1, dp);

        return dp[i][j] = false;
    }

public:
    int countSubstrings(string s) {
        int n = s.size();
        int result = 0;

        vector<vector<int > > dp(n+1, vector<int>(n+1, -1));

        for(int i  = 0; i<n; i++) {
            for(int j = i; j<n; j++) {
                if(checkPalindromeRec(s, i, j, dp)) {
                    result++;
                }
            }
        }

        return result;
    }
};