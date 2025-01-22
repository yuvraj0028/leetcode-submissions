class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        int sz = flights.size();
        vector<int> dist(n,INT_MAX);
        queue<pair<int, pair<int,int>>> q;
        unordered_map<int, vector<pair<int,int > > > adj;

        for(int i = 0;i<sz; i++){
            int u = flights[i][0];
            int v = flights[i][1];
            int wt = flights[i][2];

            adj[u].push_back({v,wt});
        }

        q.push({0,{src,0}});
        dist[src] = 0;

        while(!q.empty()){
            int n = q.size();

            while(n--){
                int stop = q.front().first;
                int node = q.front().second.first;
                int wt = q.front().second.second;

                q.pop();

                if(stop > k) continue;

                for(const auto &i : adj[node]){
                    int child = i.first;
                    int childWt = i.second;

                    if(wt + childWt < dist[child] && stop<=k){
                        q.push({stop+1,{child,childWt + wt}});
                        dist[child] = childWt + wt;
                    }
                }
            }
        }

        if(dist[dst] == INT_MAX) return -1;

        return dist[dst];
    }
};