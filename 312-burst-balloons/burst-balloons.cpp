#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx2,tune=native")

static int x = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    return 0;
}();

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

    int findMaxCoinsTabulation(vector<int>& nums){
        int n = nums.size();

        vector<vector<int > > dp(n+3, vector<int>(n+3, 0));

        nums.insert(nums.begin(), 1);
        nums.push_back(1);

        for(int i = n; i>=1; i--){
            for(int j = 1; j<=n; j++){
                if(i>j) continue;

                int maxi = INT_MIN;

                for(int index = i; index<=j; index++){
                    int cost = nums[i-1] * nums[index] * nums[j+1];
                    int left = dp[i][index-1];
                    int right = dp[index+1][j];

                    maxi = max(maxi, cost+left+right);
                }

                dp[i][j] = maxi;
            }
        }

        return dp[1][n];
    }
public:
    int maxCoins(vector<int>& nums) {
        // int n = nums.size();

        // vector<vector<int > > dp(n+3, vector<int>(n+3,-1));

        // nums.insert(nums.begin(), 1);
        // nums.push_back(1);

        return findMaxCoinsTabulation(nums);
    }
};