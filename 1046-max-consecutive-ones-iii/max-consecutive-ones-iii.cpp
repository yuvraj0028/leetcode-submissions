class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        int start = 0, end = 0;
        int ans = 0, cnt = 0;

        // for(int i = 0; i<n; i++) {
        //     int cnt = 0;
        //     for(int j = i; j<n; j++) {
        //         if(nums[j] == 0) cnt++;
        //         if(cnt<=k) {
        //             ans = max(ans, j - i +1);
        //         }
        //     }
        // }

        while(end < n) {
            if(!nums[end]) {
                cnt++;
            }

            while(cnt > k) {
                if(!nums[start]) {
                    cnt--;
                }
                start++;
            }

            ans = max(ans, end - start + 1);
            end++;
        }

        return ans;
    }
};