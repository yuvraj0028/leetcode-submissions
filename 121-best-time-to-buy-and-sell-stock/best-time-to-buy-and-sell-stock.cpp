class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxi = 0;
        int mini = prices[0];
        for(int i = 1;i<prices.size(); i++){
            if(prices[i] < mini){
                mini = prices[i];
            }
            maxi = max(maxi, abs(mini-prices[i]));
        }
        return maxi;
    }
};