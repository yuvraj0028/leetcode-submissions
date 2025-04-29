class Solution {
public:
    int countSubarrays(vector<int>& nums) {
        int i = 0, j =1, k = 2;
        int n = nums.size();

        int ans = 0;

        while(k<n){
            int a = nums[i];
            int b = nums[j];
            int c = nums[k];

            if ((a+c)*2 == b){
                ans++;
            }

            i++;
            j++;
            k++;
        }

        return ans;
    }
};