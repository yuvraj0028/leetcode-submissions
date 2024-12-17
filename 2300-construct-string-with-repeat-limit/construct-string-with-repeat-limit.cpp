class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {
        // frequency array to store count of character
        vector<int> freq(26);
        string ans = "";

        for(const char &c : s) freq[(int)c-97]++;

        // traversing from last index to maintain lexicographically order
        for(int i = 25; i>=0 ;i--){
            int temp = repeatLimit;
            
            // storing character until repeatList is exausted
            while(freq[i] && temp){
                ans+=(char)(i+97);
                freq[i]--; temp--;
            }

            // if still there are some character > repeatList
            // we will find the character next to it and append it
            // to the ans string and again store the same character
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