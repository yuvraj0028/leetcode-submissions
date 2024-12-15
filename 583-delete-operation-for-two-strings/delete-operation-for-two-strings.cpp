class Solution {
public:
    int minDistance(string word1, string word2) {      
        int n = word1.size(), m = word2.size();

        vector<vector<int > > dp(n+1, vector<int>(m+1));

        for(int i = n-1; i>=0; i--){
            for(int j = m-1; j>=0; j--){
                int ans = 0;
                if(word1[i] == word2[j]){
                    ans = 1 + dp[i+1][j+1];
                }
                ans = max(ans, max(dp[i+1][j], dp[i][j+1]));
                dp[i][j] = ans;
            }
        }
        
        return (n + m) - (2 * (dp[0][0]));
    }
};