class Solution {
private:
    int canSplit(vector<int> &nums, int k, long long mid){
        int subArrays = 1;
        int currSum = 0;

        for(auto num : nums){
            if(currSum+num<=mid){
                currSum+=num;
            } else {
                subArrays++;
                currSum = num;
                if(subArrays > k) return 0;
            }
        }

        return 1;
    }
public:
    int splitArray(vector<int>& nums, int k) {
        int s = *max_element(nums.begin(), nums.end());
        int e = accumulate(nums.begin(), nums.end(), 0);
        int ans = -1;

        while(s<=e){
            long long mid = s + (e-s)/2;

            if(canSplit(nums, k, mid)){
                ans = mid;
                e = mid-1;
            } else {
                s = mid+1;
            }
        }
        return ans;
    }
};