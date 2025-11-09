class Solution {
public:
    int characterReplacement(string s, int k) {
        int ans = 0;
        int left = 0;
        int maxFreq = 0;
        int n = s.size();
        vector<int> freq(26,0);

        for(int right = 0; right < n; right++){
            freq[s[right] - 'A']++;

            maxFreq = max(maxFreq, freq[(s[right]-'A')]);
            int winSize = right-left+1;

            if(winSize - maxFreq > k){
                freq[s[left]-'A']--;
                left++;
            }

            ans = max(ans, right-left+1);
        }
        return ans;
    }
};