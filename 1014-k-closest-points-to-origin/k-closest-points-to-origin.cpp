#define pdv pair<double, vector<int>>

class Comparator {
public:
    bool operator()(const pdv a, const pdv b){
        return a.first < b.first;
    }
};

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pdv, vector<pdv>, Comparator> pq;
        vector<vector<int > > ans;

        for(const auto &point: points) {
            double dist = sqrt(pow(point[0], 2) + pow(point[1], 2));
            // cout <<dist<<endl;
            pdv pair_ = {dist, point};
            pq.push(pair_);

            if(pq.size() > k) pq.pop();
        }

        while(!pq.empty()) {
            ans.push_back(pq.top().second);
            pq.pop();
        }

        return ans;
    }
};