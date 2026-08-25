class Solution {
public:
    bool isAnagram(string s, string t) {
        int n = s.size(), m = t.size();

        if(n!=m) return false;

        vector<int> freq(256,0);

        for(int i = 0; i<n; i++) {
            freq[s[i]]++;
            freq[t[i]]--;
        }

        for(int i = 0; i<256; i++) {
            if(freq[i]) return false;
        }

        return true;

    }
};