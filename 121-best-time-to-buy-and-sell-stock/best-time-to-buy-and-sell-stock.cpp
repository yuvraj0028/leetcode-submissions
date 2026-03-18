class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int mini = prices[0];
        int maxi = INT_MIN;

        for(int i=1; i<n; i++) {
            if(mini > prices[i]) {
                mini = prices[i];
            }
            maxi = max(maxi, abs(mini - prices[i]));
        }

        return maxi != INT_MIN ? maxi : 0;
    }
};