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

    int findMaxPartTab(vector<int>& arr, int k){
        int n = arr.size();
        vector<int> dp(n+1, -1);

        for(int i = n-1; i>=0; i--){
            int maxAns = INT_MIN;
            int maxi = INT_MIN;
            int len = 0;

            for(int j = i; j < i+k && j < n; j++){
                len++;
                maxi = max(maxi, arr[j]);

                int sum = (len * maxi) + dp[j+1];

                maxAns = max(sum, maxAns);
            }

            dp[i] = maxAns;
        }

        return dp[0] + 1;
    }

public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        // int n = arr.size();
        // vector<int> dp(n+1, -1);
        return findMaxPartTab(arr, k);
    }
};