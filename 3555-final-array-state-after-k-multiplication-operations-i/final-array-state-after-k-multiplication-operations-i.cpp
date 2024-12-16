#define PAIR pair<int,int>

class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        int n = nums.size();

        priority_queue<PAIR, vector<PAIR>, greater<PAIR>> pq;

        for(int i = 0;i<n;i++){
            pq.push({nums[i],i});
        }

        while(k--){
            PAIR top = pq.top(); pq.pop();
            top.first*=multiplier;
            pq.push(top);
        }

        while(!pq.empty()){
            PAIR top = pq.top(); pq.pop();
            nums[top.second] = top.first;
        }

        return nums;
    }
};