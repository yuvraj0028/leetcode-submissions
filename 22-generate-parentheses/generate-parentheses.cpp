class Solution {
private:
    vector<string> ans; 
    void solve(int n, string str, int open, int close) {
        if(str.size() == n*2) {
            ans.push_back(str);
            return;
        }

        if(open < n) solve(n, str+"(", open+1, close);
        if(close < open) solve(n, str+")", open, close+1);
    }

public:
    vector<string> generateParenthesis(int n) {
        solve(n, "", 0, 0);

        return ans;
    }
};