class Solution {
private:
    int dp[10001];
    
    int solve(vector<int>& nums, int i) {
        int n = nums.size();
        if (i >= n - 1) return 0;

        if (dp[i] != -1) return dp[i];

        int minJumps = 1e9;
        
        for (int j = 1; j <= nums[i]; j++) {
            minJumps = min(minJumps, 1 + solve(nums, i + j));
        }

        return dp[i] = minJumps;
    }

public:
    int jump(vector<int>& nums) {
        memset(dp, -1, sizeof(dp));
        return solve(nums, 0);
    }
};