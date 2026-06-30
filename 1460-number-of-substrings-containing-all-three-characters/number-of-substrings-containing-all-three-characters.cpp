class Solution {
public:
    int numberOfSubstrings(string s) {
        int seen[3] = {-1,-1,-1};
        int cnt = 0;
        int n = s.size();

        for(int i = 0; i<n; i++) {
            seen[s[i] - 'a'] = i;
            if(seen[0] != -1 && seen[1] != -1 && seen[2] != -1) {
                cnt += 1 + min({seen[0], seen[1], seen[2]});
            }
        }

        return cnt;
    }
};