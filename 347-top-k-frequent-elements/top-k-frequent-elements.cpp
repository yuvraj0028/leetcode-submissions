class Comparator{
public:
    bool operator()(pair<int,int > &a, pair<int,int > &b){
        return a.second > b.second;
    }
};

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        priority_queue<pair<int,int>, vector<pair<int,int > >, Comparator > pq;
        unordered_map<int,int> mp;

        for(const int &i : nums){
            mp[i]++;
        }

        for(const auto [key,val] : mp){
            pq.push({key,val});

            if(pq.size()>k){
                pq.pop();
            }
        }

        vector<int> ans;
        while(!pq.empty()){
            ans.push_back(pq.top().first);
            pq.pop();
        }

        return ans;
    }
};