class Solution {
public:
    bool isAnagram(string s, string t) {
        int n = s.size(), m = t.size();

        if(n!=m) return false;

        int freq[26] = {0};

        for(int i = 0; i<n; i++) {
            freq[s[i]-'a']++;
            freq[t[i]-'a']--;
        }

        for(int i = 0; i<26; i++) {
            if(freq[i]) return false;
        }

        return true;

    }
};