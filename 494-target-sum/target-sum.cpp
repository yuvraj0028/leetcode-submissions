class Solution {
private:
    string getKey(int a, int b){
        return to_string(a) + ", " + to_string(b);
    }

    int findWays(int i, vector<int>& nums, int target, unordered_map<string, int>& dp){
        if(i>=nums.size())
            return target == 0;

        string key = getKey(i, target);

        if(dp.count(key))
            return dp[key];

        int add = findWays(i+1, nums, target + nums[i], dp);

        int sub = findWays(i+1, nums, target - nums[i], dp);

        return dp[key] = add + sub;
    }

public:
    int findTargetSumWays(vector<int>& nums, int target) {
        unordered_map<string, int> dp;
        return findWays(0, nums, target, dp);
    }
};