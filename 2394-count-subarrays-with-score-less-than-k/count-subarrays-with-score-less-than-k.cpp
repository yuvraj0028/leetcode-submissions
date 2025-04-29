class Solution {
private:
    typedef long long ll;
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        ll sum = 0;
        ll prod = 1;
        ll cnt = 0;
        ll i = 0, j = 0;
        ll n = nums.size();

        while(j<n){
            sum+=nums[j];
            prod = sum * (j-i+1);
        
            while(prod>=k){
                sum-=nums[i++];
                prod = sum * (j-i+1);
            }

            cnt+=j-i+1;
            j++;
        }

        return cnt;
    }
};