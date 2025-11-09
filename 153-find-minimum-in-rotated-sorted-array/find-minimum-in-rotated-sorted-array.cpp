class Solution {
public:
    int findMin(vector<int>& nums) {
        int s = 0;
        int e = nums.size() - 1;
        int mini = INT_MAX;

        while(s<=e){
            int mid = s + (e-s)/2;
            
            if(nums[s] <= nums[mid]){
                mini = min(mini, nums[s]);
                s = mid+1;
            } else {
                mini = min(mini, nums[mid]);
                e = mid-1;
            }
        }

        return mini;
    }
};