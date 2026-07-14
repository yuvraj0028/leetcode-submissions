class Solution {
private:
    int robHelperRec(vector<int>& nums, vector<int> &dp, int i) {
        if(i>=nums.size()) {
            return 0;
        }

        if(dp[i] != -1) return dp[i];

        int take = nums[i] + robHelperRec(nums, dp, i+2);
        int notTake = robHelperRec(nums, dp, i+1);
    
        return dp[i] = max(take, notTake);
    }

public:
    int rob(vector<int>& nums) {
        vector<int> dp(nums.size() + 1, -1);
        return robHelperRec(nums, dp, 0);
    }
};