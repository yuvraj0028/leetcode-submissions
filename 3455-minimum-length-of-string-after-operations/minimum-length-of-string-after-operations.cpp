class Solution {
public:
    int minimumLength(string s) {
        vector<int> freq(26);
        int cnt = 0;

        for(const char &ch : s){
            freq[ch-'a']++;
        }

        for(int i = 0; i<26; i++){
            if(!freq[i]) continue;
            
            if(freq[i] %2 == 0){
                cnt+=2;
            } else {
                cnt+=1;
            }
        }

        return cnt;
    }
};