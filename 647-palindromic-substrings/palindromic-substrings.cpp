class Solution {
private:
    bool checkPalindromeRec(string &s, int i, int j, vector<vector<int > > &dp) {
        if(i>=j) return true;

        if(dp[i][j] != -1) return dp[i][j];

        if(s[i] == s[j]) return dp[i][j] = checkPalindromeRec(s, i+1, j-1, dp);

        return dp[i][j] = false;
    }

    int checkPalindromeTab(string &s) {
        int n = s.size();
        int result = n;

        if(n==0 || n==1) return n;

        vector<vector<bool > > dp(n+1, vector<bool>(n+1,false));
        for(int i =0; i<n; i++) dp[i][i] = true;

        for(int len = 2; len<=n; len++) {
            for(int i = 0; i+len-1<n; i++) {
                int j = i + len - 1;
                if(s[i] == s[j]) {
                    dp[i][j] = len == 2 ? true : dp[i+1][j-1];
                } else {
                    dp[i][j] = false;
                }

                if(dp[i][j]) {
                    result++;
                }
            }
        }

        return result;
    }

public:
    int countSubstrings(string s) {
        // int n = s.size();
        // int result = 0;

        // vector<vector<int > > dp(n+1, vector<int>(n+1, -1));

        // for(int i  = 0; i<n; i++) {
        //     for(int j = i; j<n; j++) {
        //         if(checkPalindromeRec(s, i, j, dp)) {
        //             result++;
        //         }
        //     }
        // }

        // return result;


        return checkPalindromeTab(s);
    }
};