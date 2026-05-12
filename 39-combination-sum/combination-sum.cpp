class Solution {
private:
    vector<int> temp;
    vector<vector<int > > ans;
    
    void solve(vector<int>& candidates, int target, int i) {
        if(i >= candidates.size()) {
            if(target == 0){
                ans.push_back(temp);
            }
            return;
        }

        if(target == 0) {
            ans.push_back(temp);
            return;
        }

        if(candidates[i] <= target) {
            temp.push_back(candidates[i]);
            solve(candidates, target - candidates[i], i);
            temp.pop_back();
        }

        solve(candidates, target, i+1);
    }

public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        solve(candidates, target, 0);
        return ans;
    }
};