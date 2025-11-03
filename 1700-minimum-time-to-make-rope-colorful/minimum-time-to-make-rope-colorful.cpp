class Solution {
public:
    int minCost(string s, vector<int>& cost) {
        int sum = 0;

        for(int i =0;i<cost.size()-1;i++){
            if(s[i] == s[i+1]){
                if(cost[i] <cost[i+1]){
                    sum+=cost[i];
                } else{
                    sum+=cost[i+1];
                    swap(cost[i],cost[i+1]);
                }
            }
        }

        return sum;
    }
};