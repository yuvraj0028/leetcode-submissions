class Solution {
public:
    int minSizeSubarray(vector<int>& nums, int target) {
        int n = nums.size();
        int left = 0,right = 0;
        int mini = INT_MAX;
        int curr = 0;
        
        long long totalSum = accumulate(nums.begin(), nums.end(), 0LL);
        int fullCycles = target / totalSum;
        int remSum = target % totalSum;

        while(right < 2 * n) {
            curr+=nums[right % n];

            while (curr > remSum) {
                curr-=nums[left % n];
                left++;
            }

            if(curr == remSum){
                mini = min(mini, right - left + 1);
            }

            right++;
        }

        return mini == INT_MAX ? -1 : (long long)fullCycles * n + mini;
    }
};