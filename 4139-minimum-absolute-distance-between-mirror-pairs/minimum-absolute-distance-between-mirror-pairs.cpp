class Solution {
private:
    int reverse(int n) {
        int reversed = 0;
        while(n) {
            int dig = n%10;
            reversed = (reversed * 10) + dig;
            n = n/10;
        }

        return reversed;
    }
public:
    int minMirrorPairDistance(vector<int>& nums) {
        int ans = INT_MAX;
        unordered_map<int,int> mp;

        for(int i = 0; i < nums.size(); i++) {

            if(mp.find(nums[i]) != mp.end()) {
                int lastIndex = mp[nums[i]];
                ans = min(ans, abs(i-lastIndex));
            }

            int rev = reverse(nums[i]);
            mp[rev] = i;
            
        }

        return ans == INT_MAX ? -1 : ans;
    }
};