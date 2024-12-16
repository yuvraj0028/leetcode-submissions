#define MOD 1000000007

class Solution {
private:
    int countDistinct(int i, int j, string &s, string &t, vector<vector<int > > &dp){
        if(j>=t.size()) return 1;

        if(i>=s.size()) return 0;

        if(dp[i][j] != -1) return dp[i][j];

        if(s[i] == t[j]){
            return dp[i][j] = countDistinct(i+1, j+1, s, t, dp) + countDistinct(i+1, j, s, t, dp);
        }

        return dp[i][j] = countDistinct(i+1, j, s, t, dp);
    }

    int countDistinctTabulation(string s, string t){
        int n = s.size(), m = t.size();
        vector<vector<long long > > dp(n+1, vector<long long>(m+1));

        for(int i = 0; i<=n ;i++) dp[i][m] = 1;
    
        for(int i = n-1; i>=0; i--){
            for(int j = m-1; j>=0; j--){
                long long ans = 0;
                if(s[i] == t[j]){
                    ans = (dp[i+1][j+1] % MOD + dp[i+1][j] % MOD) % MOD;
                } else {
                    ans = dp[i+1][j] % MOD;
                }
                dp[i][j] = ans % MOD;
            }
        }

        return dp[0][0] % MOD;
    }
    
public:
    int numDistinct(string s, string t) {
        return countDistinctTabulation(s, t);
    }
};