class Solution {
private:
    vector<vector<int > > subsetsList;
    void solve(vector<int>& nums, vector<int>& subset, int i) {
        if(i>=nums.size()) {
            subsetsList.push_back(subset);
            return;
        }

        solve(nums, subset, i+1);
        subset.push_back(nums[i]);
        solve(nums, subset, i+1);
        subset.pop_back();

    }

public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> subset;
        solve(nums, subset, 0);
        return subsetsList;
    }
};