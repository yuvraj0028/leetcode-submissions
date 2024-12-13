#define pii pair<int,int>

class Solution {
public:
    long long findScore(vector<int>& nums) {
        long long ans = 0;
        int n = nums.size();
        unordered_map<int,bool> mp;
        priority_queue<pii, vector<pii>, greater<pii > > pq;

        for(int i = 0;i<n;i++){
            pq.push({nums[i],i});
        }

        while(!pq.empty()){
            pii top = pq.top();
            pq.pop();

            int index = top.second;

            if(mp[index]) continue;

            if(index>0) mp[index-1] = true;

            if(index<n-1) mp[index+1] = true;

            ans+=top.first;
        }

        return ans;
    }
};