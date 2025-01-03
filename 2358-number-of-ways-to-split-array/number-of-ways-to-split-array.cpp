class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        int n = nums.size();

        long long leftSum = 0, rightSum = 0;

        long long ans = 0;

        vector<long long> leftPrefix(n);
        vector<long long> rightPrefix(n);

        for(int i = 0; i<n; i++){
            leftSum+=nums[i];

            leftPrefix[i] = leftSum;
        }

        for(int i = n-1; i>=0; i--){
            rightSum+=nums[i];

            rightPrefix[i] = rightSum;
        }

        for(int i = 0;i<n-1; i++){
            long long left = leftPrefix[i];
            long long right = rightPrefix[i+1];

            if(left >= right) ans++;
        }

        return ans;
    }
};