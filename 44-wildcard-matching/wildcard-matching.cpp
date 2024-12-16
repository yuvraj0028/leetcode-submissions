class Solution {
private:
    int dp[2001][2001];
    bool checkIfMatch(int i, int j, string &s, string &p){
        // if both string and pattern are consumed then return true because the pattern got matched
        if(i<0 && j<0) return true;

        // if pattern is consumed then return false
        if(i>=0 && j<0) return false;

        // if string is consumed but pattern is left
        if(i<0 && j>=0){
            // checking weather pattern contains '*' character
            for(int k = 0; k<=j; k++)
                if(p[k]!='*') return false;

            return true;
        }

        if(dp[i][j] != -1) return dp[i][j];

        // if current pattern is '?' we can move both i & j
        if(p[j]=='?' || s[i] == p[j]) return dp[i][j] = checkIfMatch(i-1, j-1, s, p);

        // if current pattern is '*' we can either assign empty string or make it equal to s[i]
        if(p[j] == '*') return dp[i][j] = checkIfMatch(i, j-1, s, p) || checkIfMatch(i-1, j, s, p);
    
        // if character does not match then return false
        return dp[i][j] = false;
    }

public:
    bool isMatch(string s, string p) {
        int n = s.size(), m = p.size();
        memset(dp,-1,sizeof(dp));
        return checkIfMatch(n - 1, m - 1, s, p);
    }
};