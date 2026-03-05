class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int,int> mp;

        for(int i = 0; i<n; i++){
            mp[nums[i]]++;
        }

        vector<vector<int > > bucket(n+1);
        
        for(const auto [key, val] : mp){
            bucket[val].push_back(key);
        }

        vector<int> ans;

        for(int i = n; i>=0 && ans.size() < k; i--){
            for(const auto &j : bucket[i]){
                ans.push_back(j);

                if(ans.size() == k) return ans;
            }
        }

        return ans;
    }
};