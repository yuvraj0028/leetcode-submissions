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

    int robHelperTab(vector<int>& nums) {
        int n = nums.size();

        if(n==0) return 0;

        vector<int> dp(n+1, 0);
        dp[0] = 0;
        dp[1] = nums[0];

        for(int i = 2; i<=n; i++) {
            dp[i] = max(dp[i-1], dp[i-2] + nums[i-1]);
        }

        return dp[n];
    }

public:
    int rob(vector<int>& nums) {
        // Recursion -> S.C -> O(N), T.C -> O(N)
        // vector<int> dp(nums.size() + 1, -1);
        // return robHelperRec(nums, dp, 0);

        // Tabulation -> S.C -> O(N), T.C -> O(N)
        return robHelperTab(nums);
    }
};