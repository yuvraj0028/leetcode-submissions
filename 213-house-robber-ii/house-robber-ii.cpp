class Solution {
private:
    int robHelperRec(vector<int>& nums, vector<int>& dp, int i, int n) {
        if(i >= n) return 0;

        if(dp[i] != -1) return dp[i];

        int take = nums[i] + robHelperRec(nums, dp, i+2, n);
        int notTake = robHelperRec(nums, dp, i+1, n);

        return dp[i] = max(take, notTake);
    }

    int robHelperTab(vector<int>& nums, int start, int end) {
        int length = end - start + 1;
        if(length<=0) return 0;
        if(length == 1) return nums[start];

        vector<int> dp(length, 0);

        dp[0] = nums[start];
        dp[1] = max(nums[start], nums[start+1]);

        for(int i = 2; i<length; i++) {
            int notTake = dp[i-1];
            int take = dp[i-2] + nums[start + i];

            dp[i] = max(notTake, take);
        }

        return dp[length-1];
    }
    
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return nums[0];

        // Recursion T.C -> O(N), S.C -> O(N)

        // vector<int> dp(n+1, -1);
        // int robFromFirst = robHelperRec(nums, dp, 0, n-1);

        // dp.assign(n+1, -1);
        // int robFromSecond = robHelperRec(nums, dp, 1, n);

        // return max(robFromFirst, robFromSecond);


        // Tabulation T.C -> O(N), S.C -> O(N)
        int robFirst = robHelperTab(nums, 0, n-2);
        int robSecond = robHelperTab(nums, 1, n-1);
    
        return max(robFirst, robSecond);
    }
};