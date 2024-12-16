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
public:
    int numDistinct(string s, string t) {
        int n = s.size(), m = t.size();
        vector<vector<int > > dp(n+1, vector<int>(m+1,-1));
        return countDistinct(0, 0, s, t, dp);
    }
};