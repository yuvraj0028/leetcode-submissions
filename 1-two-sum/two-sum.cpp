class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int i = 0;
        int j = 1;
        int n = nums.size();

        while(i<n){
            if(nums[i] + nums[j] == target && i!=j){
                return {i,j};
            } else if(j<n-1){
                j++; continue;
            }

            i++;
            j=1;
        }

        return {};
    }
};