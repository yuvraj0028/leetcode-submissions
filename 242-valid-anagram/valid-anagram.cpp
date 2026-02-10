class Solution {
public:
    bool isAnagram(string s, string t) {
        int n = s.size();
        int m = t.size();

        if(n!=m) return false;
        
        vector<int> freq(256);
        for(int i = 0; i<n; i++){
            freq[s[i]]++;
            freq[t[i]]--;
        }

        for(const auto &i : freq){
            if(i!=0) return false;
        }

        return true;
    }
};