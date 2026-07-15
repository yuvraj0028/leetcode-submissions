class Solution {
private:
    int robHelperRec(vector<int>& nums, vector<vector<int>>& dp, int i, int n, bool firstRobbed) {
        // Base case: out of bounds
        if (i >= n) return 0;

        // Return memoized result
        if (dp[i][firstRobbed] != -1) return dp[i][firstRobbed];

        // Option 1: Skip the current house
        int notTake = robHelperRec(nums, dp, i + 1, n, firstRobbed);

        // Option 2: Rob the current house
        int take = 0;
        
        // If we are at the very last house, we can only rob it if we DID NOT rob house 0
        if (i == n - 1) {
            if (!firstRobbed) {
                take = nums[i]; 
            }
        } else {
            // If we are at house 0 and decide to rob it, we flag 'firstRobbed' as true for the rest of the branch
            bool isFirstRobbed = (i == 0) ? true : firstRobbed;
            take = nums[i] + robHelperRec(nums, dp, i + 2, n, isFirstRobbed);
        }

        // Memoize and return the max of both choices
        return dp[i][firstRobbed] = max(take, notTake);
    }

public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        
        // Base case for a single house
        if (n == 1) return nums[0];

        // 2D DP table: n rows, 2 columns (0 for false, 1 for true)
        // dp[i][0] -> Max money from index i onwards if house 0 was NOT robbed
        // dp[i][1] -> Max money from index i onwards if house 0 WAS robbed
        vector<vector<int>> dp(n, vector<int>(2, -1));

        // Start recursion at index 0, initially house 0 hasn't been robbed
        return robHelperRec(nums, dp, 0, n, false);
    }
};