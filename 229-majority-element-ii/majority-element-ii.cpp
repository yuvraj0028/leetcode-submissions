class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> ans;
        int n = nums.size()/3;
        unordered_map<int,int> mp;

        for(const int &i : nums) mp[i]++;

        for(const auto [k,v] : mp)
            if(v > n) ans.push_back(k);

        return ans;
    }
};