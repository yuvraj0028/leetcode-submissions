class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        int i = 0, j = 0, ans = 0;

        while(i<n && j<m) {
            int num1 = nums1[i];
            int num2 = nums2[j];

            if(i<=j && num1<=num2) {
                ans = max(ans, abs(i-j));
                j++;
            } else if (num1 > num2) {
                i++; j++;
            } else {
                j++;
            }
        }

        return ans;
    }
};