class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n = s.size();
        string t(s.rbegin(),s.rend());

        vector<vector<int > > dp(n+1, vector<int>(n+1));

        for(int i = n-1; i>=0 ;i--){
            for(int j = n-1; j>=0; j--){
                int ans = 0;
                if(s[i] == t[j]){
                    dp[i][j] = 1 + dp[i+1][j+1];
                } else {
                    int a = dp[i+1][j];
                    int b = dp[i][j+1];
                    ans = max(ans,max(a,b));
                    dp[i][j] = ans;
                }
            }
        }

        return dp[0][0];
    }
};