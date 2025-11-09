class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int start = 0;
        int maxi = 0;
        int n = s.size();

        vector<int> freq(256, -1);

        for(int i = 0;i<n; i++){
            char ch = s[i];

            if(freq[ch] >= start){
                start = freq[ch] + 1;
            }

            freq[ch] = i;
            int cnt = i - start + 1;
            maxi = max(maxi, cnt);
        }

        return maxi;
    }
};