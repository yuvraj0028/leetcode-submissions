class Solution {
private:
    int dp[1001][1001];
    bool solve(string name, string typed, int i, int j){
        if(j==typed.size()) {
            return i == name.size();
        }

        if(dp[i][j] != -1) return dp[i][j];

        if(i<name.size() && name[i] == typed[j]){
            return dp[i][j] = solve(name, typed, i+1, j+1);
        } else if(j>0 && typed[j-1] == typed[j]){
            return dp[i][j] = solve(name, typed, i, j+1);
        }
        return dp[i][j] = false;
    }
public:
    bool isLongPressedName(string name, string typed) {
        memset(dp,-1,sizeof(dp));
        return solve(name, typed, 0, 0);
    }
};