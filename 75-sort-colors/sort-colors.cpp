class Solution {
public:
    void sortColors(vector<int>& nums) {
        int r = 0, w = 0;
        int b = nums.size()-1;

        while(w<=b){
            if(nums[w] == 0){
                swap(nums[w], nums[r]);
                r++;
                w++;
            } else if(nums[w] == 2){
                swap(nums[w], nums[b]);
                b--;
            } else {
                // w == 1
                w++;
            }
        }
    }
};