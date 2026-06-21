class Solution {
private:
    vector<string> ans;
    void solve(string s, int n, int open, int close) {
        if(s.size() == n*2) {
            ans.push_back(s);
            return;
        }

        if(open < n) {
            solve(s+'(', n, open+1, close);
        }

        if(close < open) {
            solve(s+')', n, open, close+1);
        }
    }
public:
    vector<string> generateParenthesis(int n) {
        string str = "";
        int open = 0, close = 0;

        solve(str, n, open, close);      
        return ans;
    }
};