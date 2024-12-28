class Solution {
private:
    long long dp[20001][4];

    int helper(vector<int>& subarraySum, int count, int i, int k){
        if(count == 0) return 0;

        if(i>=subarraySum.size()) return INT_MIN;

        if(dp[i][count] != -1) return dp[i][count];

        int include = subarraySum[i] + helper(subarraySum, count-1, i+k, k);
        int exclude = helper(subarraySum, count, i+1, k);

        return dp[i][count] = max(include, exclude);
    }

    void solve(vector<int>& subarraySum, int count, int i, int k, vector<int> & result){
        if(count == 0) return;

        if(i>=subarraySum.size()) return;

        int include = subarraySum[i] + helper(subarraySum, count - 1, i+k, k);
        int exclude = helper(subarraySum, count, i+1, k);

        if(include >= exclude) {
            result.push_back(i);
            solve(subarraySum, count-1, i+k, k, result);
        } else {
            solve(subarraySum, count, i+1, k, result);
        }
    }

public:
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        int i = 0, j = 0, sum = 0;
        int n = nums.size();

        memset(dp,-1,sizeof(dp));

        vector<int> subarraySum, result;

        while(j<n){
            sum+=nums[j];

            if(j-i+1 == k){
                subarraySum.push_back(sum);
                sum-=nums[i];
                i++;
            }

            j++;
        }

        solve(subarraySum, 3, 0, k, result);

        return result;
    }
};