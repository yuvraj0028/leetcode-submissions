class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        unordered_map<int,int> mp;

        for(int i = 0; i<n; i++) {
            int rem = target - nums[i];

            if(mp.find(nums[i]) != mp.end()) {
                return {mp[nums[i]], i};
            }

            mp[rem] = i;
        }

        return {-1,-1};
    }
};