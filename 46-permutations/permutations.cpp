class Solution {
private:
    vector<vector<int > > ans;
    void solve(vector<int>& nums, int i) {
        if(i>=nums.size()) {
            ans.push_back(nums);
            return;
        }

        for(int idx = i; idx < nums.size(); idx++) {
            swap(nums[i], nums[idx]);
            solve(nums, i+1);
            swap(nums[i], nums[idx]);
        }
    }

public:
    vector<vector<int>> permute(vector<int>& nums) {
        solve(nums, 0);
        return ans;
    }
};