class Solution {
private:
    long long dp[100001];
    long long solve(vector<long long>& values, vector<long long> &points, int i){
        if(i>=values.size()) return 0;
        
        if(dp[i] != -1) return dp[i];
        long long notTake = solve(values, points, i+1);

        int nextIdx = upper_bound(values.begin(), values.end(), values[i] + 2) - values.begin();

        long long take = points[i] + solve(values, points, nextIdx);
        return dp[i] = max(take, notTake);
    }
public:
    long long maximumTotalDamage(vector<int>& power) {
        memset(dp,-1,sizeof(dp));
        unordered_map<int,int> freq;
        for(const int &i : power) freq[i]++;

        vector<long long> points, values;
        for(const auto [k, v] : freq)
            values.push_back(k);

        sort(values.begin(), values.end());
        for(const int &i: values)
            points.push_back(1LL * i * freq[i]);

        return solve(values, points, 0);
    }
};