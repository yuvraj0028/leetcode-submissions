class Solution {
private:
    int solve(vector<int>& nums, int i, vector<vector<int > > &dp, int prev = -1){
        if(i>=nums.size()){
            return 0;
        }

        if(dp[i][prev+1] != -1) return dp[i][prev+1];
        
        int inc = 0;
        if(prev == -1 || nums[prev] < nums[i]){
            inc = 1 + solve(nums, i+1, dp, i);
        }

        int exc = solve(nums, i+1, dp, prev);
        return dp[i][prev+1] = max(inc, exc);
    }
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<vector<int > > dp(nums.size()+1, vector<int>(nums.size()+2,-1));
        return solve(nums, 0, dp);
    }
};