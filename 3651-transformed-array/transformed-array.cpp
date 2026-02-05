class Solution {
public:
    vector<int> constructTransformedArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans;

        for(int i = 0; i < n; i++){
            int num = nums[i];
            int index = INT_MAX;
            
            if(num < 0){
                index = (((i + num) % n) + n) % n;
            } else {
                index = (i + num) % n;
            }

            ans.push_back(nums[index]);
        }

        return ans;
    }
};