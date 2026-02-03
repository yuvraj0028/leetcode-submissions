class Solution {
public:
    int jump(vector<int>& nums) {
        int largest = 0;
        int currEnd = 0;
        int jumps = 0;

        for(int i = 0; i<nums.size() - 1; i++){
            largest = max(largest, i + nums[i]);

            if(currEnd == i){
                jumps++;
                currEnd = largest;
                if(currEnd >= nums.size() - 1) break;
            }
        }

        return jumps;
    }
};