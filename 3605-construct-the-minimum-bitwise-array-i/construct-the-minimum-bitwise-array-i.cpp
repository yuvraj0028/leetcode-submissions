class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, -1);
        
        for(int i = 0; i<n; i++){
            int num = nums[i];

            if(num%2 == 0) {
                continue;
            }

            int temp = num;
            int cnt = 0;

            while(temp&1){
                temp>>=1;
                cnt++;
            }

            ans[i] = num ^ (1<<(cnt-1));
            
        }

        return ans;
    }
};