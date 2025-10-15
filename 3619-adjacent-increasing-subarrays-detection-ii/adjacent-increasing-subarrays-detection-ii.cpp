class Solution {
public:
    int maxIncreasingSubarrays(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        vector<int> left(n, 1), right(n, 1);

        for(int i=1; i<n; i++){
            if(nums[i-1]<nums[i]){
                left[i] = left[i-1] + 1;
            }
        }

        for(int i=n-2; i>=0; i--){
            if(nums[i]<nums[i+1]){
                right[i] = right[i+1] + 1;
            }
        }

        for(int i=0; i<n-1; i++){
            ans = max(ans, min(left[i], right[i+1]));
        }

        return ans;
    }
};