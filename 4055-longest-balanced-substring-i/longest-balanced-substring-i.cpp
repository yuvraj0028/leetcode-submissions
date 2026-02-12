class Solution {
public:
    int longestBalanced(string s) {
        int n = s.size();
        int ans = 0;

        for(int i=0; i<n; i++){
            vector<int> freq(26,0);
            char stChar = s[i];

            for(int j = i; j<n; j++){
                freq[s[j]-'a']++;
                int stFreq = freq[stChar-'a'];

                bool flag = true;
                int temp = ans;
                for(int k = 0; k<26; k++){
                    if(stFreq == freq[k] && freq[k] != 0){
                        ans = max(ans, j-i+1);
                    } else if(freq[k] == 0){
                        continue;
                    } else {
                        flag = false;
                        break;
                    }
                }

                if(!flag){
                    ans = temp;
                }
            }
        }
        return ans;
    }
};