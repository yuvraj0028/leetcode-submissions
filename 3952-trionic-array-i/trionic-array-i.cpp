class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        int n = nums.size();
        if(n == 3) return false;

        int temp = nums[0];
        int p = INT_MIN;
        int q = INT_MIN;

        for(int i = 1; i<n; i++){
            if(nums[i] == temp) return false;
            if(nums[i] > temp){
                temp = nums[i];
                p = i;
            } else {
                break;
            }
        }

        if(p == INT_MIN || p == n-1) return false;
        
        temp = nums[p];
        for(int i = p+1; i<n; i++){
            if(nums[i] == temp) return false;
            if(nums[i] < temp){
                temp = nums[i];
                q = i;
            } else {
                break;
            }
        }

        if(q == INT_MIN || q == n-1) return false;

        temp = nums[q];

        for(int i = q+1; i<n; i++){
            if(nums[i] == temp) return false;
            if(nums[i] < temp){
                return false;
            }
            temp = nums[i];
        }

        return true;
    }
};