class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) {
        long long ans = 1;
        long long currLen = 1;

        for(int i = 1; i<prices.size(); i++){
            if(prices[i-1] - prices[i] == 1){
                currLen++;
            } else {
                currLen = 1;
            }

            ans+=currLen;
        }

        return ans;
    }
};