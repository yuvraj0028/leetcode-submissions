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

    int findLisTabulation(vector<int>& nums){
        int n = nums.size();
        vector<vector<int > > dp(n+1, vector<int>(n+1));
        
        for(int i = n-1; i>=0; i--){
            for(int prev = i-1; prev>=-1; prev--){
                int include = 0;

                if(prev == -1 || nums[prev] < nums[i]){
                    include = 1 + dp[i+1][i+1];
                }

                int exclude = dp[i+1][prev + 1];
            
                dp[i][prev+1] = max(include, exclude);
            }
        }

        return dp[0][0];

    }

    int findLisOptimized(vector<int>& nums){
        int n = nums.size();
        vector<int> curr(n+1), next(n+1);
        
        for(int i = n-1; i>=0; i--){
            for(int prev = i-1; prev>=-1; prev--){
                int include = 0;

                if(prev == -1 || nums[prev] < nums[i]){
                    include = 1 + next[i+1];
                }

                int exclude = next[prev + 1];
            
                curr[prev+1] = max(include, exclude);
            }

            next = curr;
        }

        return next[0];
    }

    int findLisNSpace(vector<int>& nums){
        int n = nums.size();
        int maxi = 1;

        vector<int> dp(n,1);

        for(int i = 0;i<n;i++){
            for(int prev = 0; prev<i;prev++){
                if(nums[i] > nums[prev])
                    dp[i] = max(1+dp[prev], dp[i]);
            }

            maxi = max(maxi, dp[i]);
        }

        return maxi;
    }

public:
    int lengthOfLIS(vector<int>& nums) {
        // int n = nums.size();
        // vector<vector<int > > dp(n+1, vector<int>(n+2,-1));
        return findLisNSpace(nums);
    }
};