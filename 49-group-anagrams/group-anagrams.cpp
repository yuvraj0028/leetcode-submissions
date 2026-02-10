class Solution {
private:
    string getHashedKey(string s){
        vector<int> freq(26);
        string key = "";
        for(const char &ch : s){
            freq[ch-'a']++;
        }

        for(int i = 0;i<26;i++){
            key+=to_string(freq[i])+"#";
        }

        return key;
    }

public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string > > mp;
        vector<vector<string>> ans;

        for(const string &s : strs){
            string key = getHashedKey(s);
            mp[key].push_back(s);
        }

        for(const auto itr : mp){
            ans.push_back(itr.second);
        }

        return ans;
    }
};