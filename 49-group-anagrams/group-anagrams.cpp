class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> um;
        for(string str:strs){
            string hash=calHash(str);
            um[hash].push_back(str);
        }
        vector<vector<string>> result;
        for(const auto &res:um){
            result.push_back(res.second);
        }

        return result;
    }

    string calHash(string str){
        int bucket[26]={0};
        for (char c:str){
            bucket[c-'a']++;
        }

        string result="#";
        for (int i = 0; i < 26; i ++) {
            if (bucket[i] == 0) {
                continue;
            }

            result += to_string(bucket[i]);
            result.push_back((char)('a' + i));
        }

        return result;
    }
};