class Solution {
private:
    bool checkPalindromeRec(string &s, int i, int j, vector<vector<int > > &dp) {
        if(i>=j) return true;

        if(dp[i][j] != -1) return dp[i][j];

        if(s[i] == s[j]) {
            return dp[i][j] = checkPalindromeRec(s, i+1, j-1, dp);
        }

        return dp[i][j] = false;
    }
public:
    string longestPalindrome(string s) {
        int maxLen = 0;
        int startingIndex = 0;

        int n = s.size();
        vector<vector<int > > dp(n+1, vector<int>(n+1, -1));

        for(int i = 0; i<n; i++) {
            for(int j = 0; j<n; j++) {
                int currLen = j-i+1;
                if(checkPalindromeRec(s, i, j, dp)) {
                    if(currLen > maxLen) {
                        maxLen = currLen;
                        startingIndex = i;
                    }
                }
            }
        }

        return s.substr(startingIndex, maxLen);
    }
};