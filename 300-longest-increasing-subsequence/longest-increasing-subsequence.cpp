class Solution {
private:
    int findLIS(int i, vector<int>& nums, vector<vector<int > > &dp, int prev = -1){
        if(i>=nums.size()) return 0;

        if(dp[i][prev+1] != -1) return dp[i][prev+1];

        int include = 0;

        if(prev == -1 || nums[prev] < nums[i]){
            include = 1 + findLIS(i+1, nums, dp, i);
        }

        int exclude = findLIS(i+1, nums, dp, prev);
    
        return dp[i][prev+1] = max(include, exclude);
    }

public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int > > dp(n+1, vector<int>(n+2,-1));
        return findLIS(0, nums,dp);
    }
};