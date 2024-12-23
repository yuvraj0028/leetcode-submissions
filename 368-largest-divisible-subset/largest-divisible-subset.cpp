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
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans, temp, dp(n,-1);

        sort(nums.begin(), nums.end());

        findSubset(0,nums,temp,ans,dp);

        return ans;
    }
};