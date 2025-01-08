class Solution {
public:
    bool isAnagram(string s, string t) {
        int n = s.size();
        int m = t.size();

        if(n != m) return false;
        
        unordered_map<char, int> mp;

        for(const char &ch : s) mp[ch]++;

        for(const char &ch : t){
            if(mp[ch] > 0){
                mp[ch]--;
            } else {
                return false;
            }
        }

        return true;
    }
};