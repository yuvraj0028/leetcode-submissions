class Solution {
private:
    vector<int> temp;
    set<vector<int > > ans;
    void solve(vector<int> &nums, int i) {
        if(i>=nums.size()) {
            ans.insert(temp);
            return;
        }

        solve(nums, i+1);
        temp.push_back(nums[i]);
        solve(nums, i+1);
        temp.pop_back();

    }

public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        solve(nums, 0);
        vector<vector<int>> res(ans.begin(), ans.end());
        return res;
    }
};