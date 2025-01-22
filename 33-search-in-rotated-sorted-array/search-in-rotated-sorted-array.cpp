class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int s = 0;
        int e = n-1;
        
        while(s<=e){
            int mid = (s+e)/2;

            if(nums[mid] == target) return mid;

            if(nums[s] == nums[mid] && nums[e] == nums[mid]){
                s++;
                e--;
            } else if(nums[s] <= nums[mid]){
                if(nums[s]<=target && nums[mid] >= target){
                    e = mid-1;
                } else {
                    s = mid+1;
                }
            } else {
                if(nums[e]>=target && nums[mid] <= target){
                    s = mid+1;
                } else {
                    e = mid-1;
                }
            }
        }

        return -1;
    }
};