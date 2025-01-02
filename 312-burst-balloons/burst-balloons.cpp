class Solution {
private:
    int findMaxCoins(vector<int>& nums, int i, int j, vector<vector<int > > &dp){
        if(i>j) return 0;

        if(dp[i][j] != -1) return dp[i][j];

        int maxi = INT_MIN;

        for(int index = i; index<=j; index++){
            int cost = nums[i-1] * nums[index] * nums[j+1];
            int left = findMaxCoins(nums, i, index-1, dp);
            int right = findMaxCoins(nums, index+1, j, dp);

            maxi = max(maxi, cost+left+right);
        }

        return dp[i][j] = maxi;
    }
public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size();

        vector<vector<int > > dp(n+3, vector<int>(n+3,-1));

        nums.insert(nums.begin(), 1);
        nums.push_back(1);

        return findMaxCoins(nums, 1, n, dp);
    }
};