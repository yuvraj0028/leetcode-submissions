class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        int start = 0;
        int n = s.size();
        int ans = INT_MIN;
        vector<int> freq(256,-1);

        for(int i = 0; i<n; i++){
            if(freq[s[i]] >= start){
                start = freq[s[i]] + 1;
            }

            freq[s[i]] = i;
            int cnt = i - start + 1;
            ans = max(ans, cnt);
        }

        return ans == INT_MIN ? 0 : ans;
    }
};