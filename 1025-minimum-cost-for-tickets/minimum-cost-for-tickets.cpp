class Solution {
private:
    int findMinCost(vector<int> &days, vector<int> &costs, int i){
        if(i>=days.size()){
            return 0;
        }

        int day_1 = costs[0] + findMinCost(days, costs, i+1);

        int index;

        for(index = i; index<days.size() && days[index]<days[i] + 7; index++);

        int day_7 = costs[1] + findMinCost(days, costs, index);

        for(index = i; index<days.size() && days[index]<days[i] + 30; index++);

        int day_30 = costs[2] + findMinCost(days, costs, index);

        return min({day_1, day_7, day_30});
    }

    int findMinCostTabulation(vector<int>& days, vector<int>& costs){
        int n = days.size();

        vector<int> dp(n+1);

        for(int i = n-1; i>=0; i--){
            int day_1 = costs[0] + dp[i+1];

            int index;

            for(index = i; index<days.size() && days[index]<days[i] + 7; index++);

            int day_7 = costs[1] + dp[index];

            for(index = i; index<days.size() && days[index]<days[i] + 30; index++);

            int day_30 = costs[2] + dp[index];

            dp[i] = min({day_1, day_7, day_30});
        }

        return dp[0];
    }

public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        return findMinCostTabulation(days, costs);
    }
};