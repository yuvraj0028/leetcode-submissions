class Solution {
private:
    void findCombinationSum(vector<int>& candidates, vector<int>& temp, vector<vector<int>>& ans, int target, int i){
        if(i>=candidates.size()){
            if(target == 0){
                ans.push_back(temp);
            }
            return;
        }

        int num = candidates[i];
        findCombinationSum(candidates, temp, ans, target, i+1);

        if(num <= target){
            temp.push_back(num);
            findCombinationSum(candidates, temp, ans, target-num, i);
            temp.pop_back();
        }
    }

public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> temp;
        int i = 0;

        findCombinationSum(candidates, temp, ans, target, i);
        return ans;
    }
};