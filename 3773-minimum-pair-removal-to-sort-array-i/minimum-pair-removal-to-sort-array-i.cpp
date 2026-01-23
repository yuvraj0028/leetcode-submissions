class Solution {
public:
    int minimumPairRemoval(vector<int>& nums) {
        int cnt = 0;
        while(true){
            bool isUnsorted = 0;

            for(int i = 1; i<nums.size(); i++){
                if(nums[i-1] > nums[i]){
                    isUnsorted = 1;
                    break;
                }
            }

            if(!isUnsorted) break;

            int replaceIndex = -1;
            int currSum = INT_MAX;
            for(int i = 0; i<nums.size()-1; i++){
                int tempSum = nums[i] + nums[i+1];
                if(currSum > tempSum){
                    currSum = tempSum;
                    replaceIndex = i;
                }
            }


            nums[replaceIndex] = currSum;
            nums.erase(nums.begin() + replaceIndex + 1);
            cnt++;
        }

        return cnt;
    }
};