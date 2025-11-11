class Solution {
private:
    vector<int> dp;
    int solve(string s, int i){
        if(i>=s.size()) return 1;
        if(s[i] == '0') return 0;

        if(dp[i] != -1) return dp[i];

        int ans = solve(s,i+1);

        if(i+1<s.size() && (s[i] == '1' || s[i] == '2' && s[i+1]<='6')){
            ans+=solve(s,i+2);
        }
        
        return dp[i] = ans;
    }

public:
    int numDecodings(string s) {
        dp.resize(s.size()+1, -1);
        return solve(s,0);
    }
};