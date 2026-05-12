class Solution {
private:
    vector<int> temp;
    vector<vector<int > > ans;
    
    void solve(vector<int>& candidates, int target, int i){
        if(target == 0) {
            ans.push_back(temp);
            return;
        }

        for(int idx = i; idx < candidates.size(); idx++) {
            if(idx > i && candidates[idx] == candidates[idx - 1]) continue;
            if(candidates[idx] > target) break;
            temp.push_back(candidates[idx]);
            solve(candidates, target - candidates[idx], idx + 1);
            temp.pop_back();
        }
    }

public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        solve(candidates, target, 0);
        return ans;
    }
};