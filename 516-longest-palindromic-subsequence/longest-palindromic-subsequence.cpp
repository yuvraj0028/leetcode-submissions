class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n = s.size();
        string t(s.rbegin(),s.rend());

        vector<int> curr(n+1), next(n+1);

        for(int i = n-1; i>=0 ;i--){
            for(int j = n-1; j>=0; j--){
                int ans = 0;
                if(s[i] == t[j]) ans = 1 + next[j+1];
                ans = max(ans,max(next[j],curr[j+1]));
                curr[j] = ans;
            }
            next = curr;
        }

        return next[0];
    }
};