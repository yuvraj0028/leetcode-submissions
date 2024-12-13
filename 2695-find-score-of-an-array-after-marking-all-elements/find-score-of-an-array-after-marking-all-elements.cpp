#define pii pair<int,int>

class Solution {
public:
    long long findScore(vector<int>& nums) {
        long long ans = 0;
        int n = nums.size();
        vector<int> marked(n);
        priority_queue<pii, vector<pii>, greater<pii > > pq;

        for(int i = 0;i<n;i++){
            pq.emplace(nums[i],i);
        }

        while(!pq.empty()){
            pii top = pq.top();
            pq.pop();

            int index = top.second;

            if(marked[index]) continue;

            if(index>0) marked[index-1] = true;

            if(index<n-1) marked[index+1] = true;

            ans+=top.first;
        }

        return ans;
    }
};