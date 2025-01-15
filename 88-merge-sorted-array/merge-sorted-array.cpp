class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        if(m == 0){
            nums1 = nums2;
            return;
        }

        if(n == 0){
            return;
        }

        vector<int> ans(m+n);
        
        for(int i = 0; i<n; i++)
            nums1.pop_back();

        m = nums1.size();

        int i = 0, j = 0, k = 0;

        while(i<m && j<n){
            if(nums1[i] < nums2[j]){
                ans[k++] = nums1[i++];
            } else {
                ans[k++] = nums2[j++];
            }
        }

        while(i<m){
            ans[k++] = nums1[i++];
        }

        while(j<n){
            ans[k++] = nums2[j++];
        }

        nums1 = ans;
    }
};