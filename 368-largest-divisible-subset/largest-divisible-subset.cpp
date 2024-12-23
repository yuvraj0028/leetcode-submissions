class Solution {
private:
    void findSubset(int i, vector<int>& nums, vector<int>& temp, vector<int>& ans, vector<int>& dp){
        if(i>=nums.size()){
            if(ans.size()<temp.size()){
                ans = temp;
            }

            return;
        }


        // include current element
        if((temp.size() == 0 || nums[i] % temp.back() == 0) && (dp[i] < (int)temp.size() + 1)){
            dp[i] = temp.size() + 1;
            temp.push_back(nums[i]);

            findSubset(i+1, nums, temp, ans, dp);
            
            temp.pop_back();
        }

        // exclude current element
        findSubset(i+1, nums, temp, ans, dp);
    }

    vector<int> findSubsetTabulation(vector<int>& nums){
        int n = nums.size();
        int maxi = 1, lastIndex = 0;
        vector<int> dp(n,1), hash(n), ans;

        sort(nums.begin(), nums.end());

        for(int i = 1; i<n; i++){
            hash[i] = i;
            for(int prev = 0; prev<i;prev++){
                if(nums[i] % nums[prev] == 0 && dp[i] < dp[prev] + 1){
                    dp[i] = dp[prev] + 1;
                    hash[i] = prev;
                }
            }

            if(dp[i] > maxi){
                maxi = dp[i];
                lastIndex = i;
            }
        }

        ans.push_back(nums[lastIndex]);

        while(hash[lastIndex] != lastIndex){
            lastIndex = hash[lastIndex];
            ans.push_back(nums[lastIndex]);
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        // int n = nums.size();
        // vector<int> ans, temp, dp(n,-1);

        // sort(nums.begin(), nums.end());

        // findSubset(0,nums,temp,ans,dp);

        return findSubsetTabulation(nums);
    }
};