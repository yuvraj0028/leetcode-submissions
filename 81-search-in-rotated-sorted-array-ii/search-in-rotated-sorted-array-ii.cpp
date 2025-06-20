class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int s = 0;
        int e = nums.size() - 1;

        while(s<=e){
            int mid = s + (e - s)/2;

            if(nums[mid]==target){
                return 1;
            }

            if(nums[s] == nums[mid] && nums[e] == nums[mid]){
                s++;
                e--;
            }
            // left sorted part
            else if(nums[s] <= nums[mid]){
                if(nums[s]<=target && nums[mid]>target){
                    e = mid-1;
                } else {
                    s = mid+1;
                }
            }
            // right sorted part
            else {
                if(nums[e]>=target && nums[mid]<target){
                    s = mid+1;
                } else {
                    e = mid-1;
                }
            }
        }

        return 0;
    }
};