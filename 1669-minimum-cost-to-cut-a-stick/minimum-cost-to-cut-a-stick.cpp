class Solution {
private:
    vector<vector<int > > dp;
    int findMinCost(vector<int> &cuts, int i, int j){
        if(i>j) return 0;

        if(dp[i][j] != -1) return dp[i][j];

        int mini = INT_MAX;

        for(int index = i; index<=j; index++){
            int cost = cuts[j+1] - cuts[i-1] 
                + findMinCost(cuts, i, index-1)
                + findMinCost(cuts, index+1, j);

            mini = min(cost, mini);
        }

        return dp[i][j] = mini;
    }
public:
    int minCost(int n, vector<int>& cuts) {
        int sz = cuts.size();

        dp.resize(sz+3, vector<int>(sz+3,-1));

        cuts.push_back(n);
        cuts.insert(cuts.begin(), 0);
        sort(cuts.begin(), cuts.end());

        return findMinCost(cuts, 1, sz);

    }
};