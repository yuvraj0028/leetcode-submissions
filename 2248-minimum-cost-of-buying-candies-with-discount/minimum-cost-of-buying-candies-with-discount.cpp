class Solution {
public:
    int minimumCost(vector<int>& cost) {
        int i = 0, j = 1, ans = 0;

        sort(cost.rbegin(), cost.rend());
        while(i<cost.size()) {
            ans+=cost[i];
            
            if(j<cost.size()) {
                ans+=cost[j];
            }

            i = j+2;
            j = i+1;
        }

        return ans;
    }
};