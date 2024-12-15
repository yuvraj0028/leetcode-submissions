class Solution {
private:
    int findMinDist(string &s1, string &s2){
        int n = s1.size(), m = s2.size();
        
        vector<vector<int > > dp(n+1, vector<int>(m+1));

        for(int i=1 ; i<=n ; i++) dp[i][0] = i;
        for(int j=1 ; j<=m ; j++) dp[0][j] = j;
    
        for(int i = 1 ;i<=n; i++){
            for(int j = 1; j<=m; j++){
                if(s1[i-1] == s2[j-1]) dp[i][j] = dp[i-1][j-1];
                else {
                    int replace = 1 + dp[i-1][j-1];
                    int insert = 1 + dp[i-1][j];
                    int del = 1 + dp[i][j-1];

                    dp[i][j] = min({replace, insert, del});
                }
            }
        }

        return dp[n][m];
    }

public:
    int minDistance(string word1, string word2) {
        return findMinDist(word1, word2);
    }
};