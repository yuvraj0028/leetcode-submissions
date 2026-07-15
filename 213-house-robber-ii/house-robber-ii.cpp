class Solution {
private:
    int robHelperRec(vector<int>& nums, vector<int>& dp, int i, int n) {
        if(i >= n) return 0;

        if(dp[i] != -1) return dp[i];

        int take = nums[i] + robHelperRec(nums, dp, i+2, n);
        int notTake = robHelperRec(nums, dp, i+1, n);

        return dp[i] = max(take, notTake);
    }
public:
    int rob(vector<int>& nums) {
        int n = nums.size();

        if(n==1) return nums[0];

        vector<int> dp(n+1, -1);
        int robFromFirst = robHelperRec(nums, dp, 0, n-1);

        dp.assign(n+1, -1);
        int robFromSecond = robHelperRec(nums, dp, 1, n);

        return max(robFromFirst, robFromSecond);
    }
};