class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {
        vector<int> freq(26);
        string ans = "";

        for(const char &c : s) freq[c-'a']++;

        for(int i = 25; i>=0 ;i--){
            int temp = repeatLimit;

            while(freq[i] && temp){
                ans+=(char)(i+97);
                freq[i]--; temp--;
            }

            if(freq[i]){
                for(int j = i - 1; j>=0; j--){
                    if(freq[j]){
                        ans+=(char)(j+97);
                        freq[j]--;
                        i++;
                        break;
                    }
                }
            }
        }

        return ans;
    }
};