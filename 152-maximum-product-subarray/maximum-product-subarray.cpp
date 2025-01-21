class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int currProd = 1;
        int n = nums.size();

        int ans = INT_MIN;

        for(int i = 0; i<n; i++){
            currProd*=nums[i];

            ans = max(ans, currProd);

            if(currProd == 0) currProd = 1;
        }

        currProd = 1;

        for(int i = n-1; i>=0; i--){
            currProd*=nums[i];

            ans = max(ans, currProd);
        
            if(currProd == 0) currProd = 1;
        }

        return ans;
    }
};