class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string > > mp;

        for(string str : strs){
            int freq[26] = {0};
            for(char ch : str) freq[ch-'a']++;

            string key = "";
            for(int i : freq){
                key+=((char)(i+'a') + '#');
            }

            mp[key].push_back(str);
        }

        vector<vector<string > > res;
        for(const auto [k,v] : mp){
            res.push_back(v);
        }

        return res;
    }
};