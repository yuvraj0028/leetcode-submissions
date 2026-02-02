class Solution {
private:
    int dp[100001];
    bool solve(vector<int>& nums, int i){
        int n = nums.size();
        
        if(i >= n - 1) return true;

        if(nums[i] == 0) return false;
        
        if(dp[i] != -1) return dp[i];

        int num = nums[i];

        int mini = min(i + nums[i], n-1);

        for(int j = mini; j>i; j--){
            if(solve(nums, j)){
                return dp[i] = 1;
            }
        
        }

        return dp[i] = 0;
    }

public:
    bool canJump(vector<int>& nums) {
        memset(dp, -1, sizeof(dp));
        return solve(nums, 0);
    }
};