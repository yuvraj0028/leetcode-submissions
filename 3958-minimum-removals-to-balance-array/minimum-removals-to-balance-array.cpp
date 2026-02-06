class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {
        int i = 0;
        int j = 0;
        int ans = 0;

        int n = nums.size();
        sort(nums.begin(), nums.end());

        while(j<n){
            while((long long)(nums[j]) > (long long)(nums[i]) * k){
                i++;
            }

            ans = max(ans, j-i+1);
            j++;
        }

        return n - ans;
    }
};