class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& nums) {
        unordered_map<string, int> mp;

        int n = nums.size();
        int cnt = 0;

        for(int i = 0; i<n; i++){
            int mini = min(nums[i][0], nums[i][1]);
            int maxi = max(nums[i][0], nums[i][1]);
            char a = mini + 48;
            char b = maxi + 48;

            string key = to_string(a) + "-" + to_string(b);

            cnt+=mp[key];
            mp[key]++;
        }

        return cnt;
    }
};