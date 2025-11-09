class Comparator {
public:
    bool operator()(pair<int,int> a, pair<int,int> b){
        return a.second > b.second;
    }
};

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        vector<int> vec;
        priority_queue<pair<int,int >, vector<pair<int,int > >, Comparator> pq;
    
        for(const int &i : nums) mp[i]++;

        for(auto i : mp){
            pq.push(i);
            if(pq.size() > k){
                pq.pop();
            }
        }

        while(!pq.empty()){
            vec.push_back(pq.top().first);
            pq.pop();
        }

        return vec;
    }
};