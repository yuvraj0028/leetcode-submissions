class Solution {
public:
    bool isAnagram(string s, string t) {
        int n = s.size();
        int m = t.size();

        if(n != m) return false;
        
        vector<int> freq(256);

        for(const char &ch : s) freq[ch]++;

        for(const char &ch : t){
            if(freq[ch] > 0){
                freq[ch]--;
            } else {
                return false;
            }
        }

        return true;
    }
};