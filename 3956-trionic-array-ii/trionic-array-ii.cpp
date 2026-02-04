class Solution {
public:
    typedef long long ll;
    ll maxSumTrionic(vector<int>& nums) {
        int n = nums.size();
        
        ll maxSum = LLONG_MIN;
        int i = 0;
        while (i < n) {
            // 1) Skip any non-increasing run (we need to start at the beginning of an ascent)
            while (i + 1 < n && nums[i + 1] <= nums[i]) {
                i++;
            }

            // 2) Strictly Increasing: [l .. p]
            int l = i;
            ll currSum = 0;
            while (i + 1 < n && nums[i + 1] > nums[i]) {
                currSum += nums[i];
                i++;
            }
            int p = i;
            if (p == l) { // p must be > l
                i++;
                continue;
            }

            // 3) Optionally drop initial negative values within the ascent
            //    (this lets us maximize the sum of the left side)
            {
                ll prefixSum = currSum;
                ll remove = 0;
                int j = l;
                // as long as the first leg has more than one element and the next is ≤ 0
                while (j < p - 1 && nums[j] <= 0) {
                    remove += nums[j];
                    currSum = max(currSum, prefixSum - remove);
                    j++;
                }
            }

            // 4) Strictly Decreasing: [p .. q]
            while (i + 1 < n && nums[i + 1] < nums[i]) {
                currSum += nums[i];
                i++;
            }
            int q = i;
            if (p == q) { // q must be > p
                i++;
                continue;
            }

            // 5) Strictly Increasing: [q .. r]
            int nextL = i; // We will be using this, to start our next trionic array
            int stepsUp = 0;
            while (i + 1 < n && nums[i + 1] > nums[i]) {
                currSum += nums[i];

                // only once we’ve climbed at least one step do we have a full “trionic”
                if (stepsUp >= 1) {
                    maxSum = max(maxSum, currSum);
                }

                stepsUp++;
                i++;
            }

            if (stepsUp >= 1 && i < n) {
                // We got our first trionic array
                if(stepsUp == 1 && maxSum == LLONG_MIN) { 
                    maxSum = currSum + nums[i];
                } else { // Check if the current trionic array is better than the previous
                    maxSum = max(maxSum, currSum + nums[i]);
                } 
            }

            // 7) Reset i back to the start of this last ascent 
            i = nextL;
        }

        return maxSum;
    }
};