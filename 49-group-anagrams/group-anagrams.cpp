class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) 
    {
        vector<vector<string>> output;
        unordered_map<string, vector<string>> outputMap;

        for (const auto& s : strs)
        {
            string sCopy = s;
            sort(sCopy.begin(),sCopy.end());
            outputMap[sCopy].push_back(s);
        }

        for (auto& [_, x] : outputMap)
            output.push_back(x);

        return output;
    }
};