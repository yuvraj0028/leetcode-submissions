class Solution {
private:
    int findMinDist(int i, int j, string &s1, string &s2, vector<vector<int > > &dp){
        if(i>=s1.size()) return s2.size() - j;

        if(j>=s2.size()) return s1.size() - i;

        if(dp[i][j] != -1) return dp[i][j];

        if(s1[i] == s2[j]) return findMinDist(i+1, j+1, s1, s2, dp);

        int replace = 1 + findMinDist(i+1, j+1, s1, s2, dp);
        int insert = 1 + findMinDist(i+1, j, s1, s2, dp);
        int del = 1 + findMinDist(i, j+1, s1, s2, dp);

        return dp[i][j] = min({replace, insert, del});
    }

public:
    int minDistance(string word1, string word2) {
        int n = word1.size(), m = word2.size();

        vector<vector<int > > dp(n+1, vector<int>(m+1, -1));

        return findMinDist(0, 0, word1, word2, dp);
    }
};