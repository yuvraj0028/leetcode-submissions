class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        int n = str1.size(), m = str2.size();
        string commonSeq = "";

        // DP Table to store lcs
        vector<vector<int > > dp(n+1, vector<int>(m+1));
        
        for(int i = n-1;i>=0;i--){
            for(int j = m - 1; j>=0;j--){
                int ans = 0;

                if(str1[i] == str2[j]){
                    ans = 1 + dp[i+1][j+1];
                }

                ans = max({ans, dp[i+1][j], dp[i][j+1]});
                
                dp[i][j] = ans;
            }
        }

        int i = 0, j = 0;

        // processing the DP Table
        while(i<n && j<m){
            if(str1[i] == str2[j]){
                commonSeq+=str1[i];
                i++; j++;
            } else if(dp[i+1][j] > dp[i][j+1]){
                commonSeq+=str1[i];
                i++;
            } else {
                commonSeq+=str2[j];
                j++;
            }
        }

        // if any part of string is left make sure to include it :)
        while(i<n) commonSeq+=str1[i++];
        while(j<m) commonSeq+=str2[j++];

        return commonSeq;
    }
};