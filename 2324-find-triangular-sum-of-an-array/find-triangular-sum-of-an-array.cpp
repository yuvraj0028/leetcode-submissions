class Solution {
public:
    int triangularSum(vector<int>& nums) {
        int n = nums.size();
        for (int k = n; k > 1; --k) {
            for (int i = 0; i < k - 1; ++i) {
                nums[i] = (nums[i] + nums[i + 1]) % 10;
            }
        }
        return nums[0];
    }
};
