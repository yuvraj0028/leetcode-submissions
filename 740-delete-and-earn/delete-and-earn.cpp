class Solution {
private:
    int dp[10001];
    int solve(vector<int>& values, vector<int> &points, int i){
        if(i>=values.size()) return 0;
        if(i == values.size() - 1) return points[i];

        if(dp[i] != -1) return dp[i];

        if(values[i+1] == values[i] + 1){
            int take = points[i] + solve(values, points, i+2);
            int notTake = solve(values, points, i+1);
            
            return dp[i] = max(take, notTake);
        } else {
            return dp[i] = points[i] + solve(values, points, i+1);
        }
    }
public:
    int deleteAndEarn(vector<int>& nums) {
        memset(dp,-1,sizeof(dp));
        unordered_map<int,int> freq;
        for(const int &i : nums) freq[i]++;

        vector<int> points, values;
        for(const auto [k, v] : freq)
            values.push_back(k);

        sort(values.begin(), values.end());
        for(const int &i: values)
            points.push_back(i * freq[i]);

        return solve(values, points, 0);
    }
};