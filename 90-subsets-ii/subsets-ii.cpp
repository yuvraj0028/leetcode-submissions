class Solution {
private:
    vector<int> temp;
    vector<vector<int > > ans;
    void solve(vector<int> &nums, int i) {
        ans.push_back(temp);

        for(int idx = i; idx < nums.size(); idx++) {
            if(idx > i && nums[idx] == nums[idx-1]) continue;
            temp.push_back(nums[idx]);
            solve(nums, idx+1);
            temp.pop_back();
        }
    }

public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        solve(nums, 0);
        return ans;
    }
};