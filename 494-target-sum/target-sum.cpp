class Solution {
private:
    int findWays(int i, vector<int>& nums, int target){
        if(i>=nums.size())
            return target == 0;

        int add = findWays(i+1, nums, target + nums[i]);

        int sub = findWays(i+1, nums, target - nums[i]);

        return add + sub;
    }

public:
    int findTargetSumWays(vector<int>& nums, int target) {
        return findWays(0, nums, target);
    }
};