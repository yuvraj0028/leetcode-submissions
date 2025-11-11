class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size(), cnt = 0;
        vector<vector<int > > dp(n, vector<int>(n,0));

        for(int i=0; i<n; i++){
            for(int j=0, k=i; k<n; j++, k++){
                if(i == 0){
                    dp[j][k] = 1;
                } else if(i == 1 && s[j] == s[k]){
                    dp[j][k] = 1;
                } else if(s[j] == s[k] && dp[j+1][k-1]) {
                    dp[j][k] = 1;
                }

                if(dp[j][k]){
                    cnt++;
                }
            }
        }

        return cnt;
    }
};