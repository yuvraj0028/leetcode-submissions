class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int start = 0;
        int len = 0;
        
        vector<int> seen(256,-1);

        for(int i = 0; i<n; i++) {
            char ch = s[i];

            if(seen[ch] >= start) {
                start = 1 + seen[ch];
            }

            seen[ch] = i;
            len = max(len, i - start + 1);
        }

        return len;
    }
};