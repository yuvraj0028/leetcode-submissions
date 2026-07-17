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

    string getPalindromeTab(string &s) {
        int n = s.size();
        if (n == 0) return "";

        vector<vector<bool > > dp(n+1, vector<bool>(n+1, false));
        int maxLen = 1, startingIndex = 0;

        for (int i = 0; i < n; i++) dp[i][i] = true;

        for(int len = 2; len<=n; len++) {
            for(int i = 0; i+len-1<n; i++) {
                int j = i + len - 1;
                if(s[i] == s[j]) {
                    dp[i][j] = len == 2 ? true : dp[i+1][j-1];
                } else {
                    dp[i][j] = false;
                }

                if(dp[i][j] && len > maxLen) {
                    maxLen = len;
                    startingIndex = i;
                }
            }
        }

        return s.substr(startingIndex, maxLen);
    }

    string getPalindromeTabConstant(string &s) {
        if(s.empty()) return "";
        int maxLen = 1, startingIndex = 0;

        auto expand = [&](int l, int r) {
            while(l>=0 && r<(int)s.size() && s[l] == s[r]) {
                l--;
                r++;
            }

            int len = r-l-1;

            if(len > maxLen) {
                startingIndex = l+1;
                maxLen = len;
            }
        };

        for(int i = 0; i<(int)s.size(); i++) {
            expand(i,i);
            expand(i,i+1);
        }

        return s.substr(startingIndex, maxLen);
    }

public:
    string longestPalindrome(string s) {
        // int maxLen = 0;
        // int startingIndex = 0;

        // int n = s.size();
        // vector<vector<int > > dp(n+1, vector<int>(n+1, -1));

        // for(int i = 0; i<n; i++) {
        //     for(int j = 0; j<n; j++) {
        //         int currLen = j-i+1;
        //         if(checkPalindromeTab(s, i, j, dp)) {
        //             if(currLen > maxLen) {
        //                 maxLen = currLen;
        //                 startingIndex = i;
        //             }
        //         }
        //     }
        // }

        // return s.substr(startingIndex, maxLen);
    
        // return getPalindromeTab(s);

        return getPalindromeTabConstant(s);
    }
};