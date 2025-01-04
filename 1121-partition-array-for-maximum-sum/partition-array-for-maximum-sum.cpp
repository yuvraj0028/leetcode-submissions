class Solution {
private:
    int findMaximumPartition(vector<int>& arr, int k, int i, vector<int> &dp){
        if(i >= arr.size()) return 0;

        if(dp[i] != -1) return dp[i];

        int maxAns = INT_MIN;
        int maxi = INT_MIN;
        int len = 0;

        for(int j = i; j < i+k && j < arr.size(); j++){
            len++;
            maxi = max(maxi, arr[j]);

            int sum = (len * maxi) + findMaximumPartition(arr, k, j+1, dp);

            maxAns = max(sum, maxAns);
        }

        return dp[i] = maxAns;
    }


public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> dp(n+1, -1);
        return findMaximumPartition(arr, k, 0, dp);
    }
};