class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        int n = nums.size();
        
        if(n == 1) return 0;
        sort(nums.begin(), nums.end(), greater<int>());
        int ans = INT_MAX;

        for(int i = 0; i<=n-k; i++){
            int a = nums[i];
            int b = nums[i+k-1];

            cout<<a<< " "<<b<<endl;

            ans = min(ans, a - b);
        }

        return ans;
    }
};