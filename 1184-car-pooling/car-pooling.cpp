class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        vector<int> temp(1001, 0);

        for(auto vec : trips){
            int val = vec[0];
            int from = vec[1];
            int to = vec[2];

            temp[from]+=val;
            temp[to]-=val;
        }
        
        int sum = 0;

        for(int i = 0; i<1001; i++){
            sum+=temp[i];

            if(sum>capacity) return 0;
        }

        return 1;
    }
};