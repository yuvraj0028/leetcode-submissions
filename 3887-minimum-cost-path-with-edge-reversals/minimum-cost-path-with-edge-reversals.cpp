class Solution {
public:
    int minCost(int n, vector<vector<int>>& edges) {
        unordered_map<int, vector<pair<int,int > > > adjList;
        
        for(const auto &edge : edges){
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];

            adjList[u].push_back({v,w});
            adjList[v].push_back({u,2*w});
        }

        vector<int> dist(n, INT_MAX);
        queue<pair<int, int > > q;

        q.push({0,0});
        dist[0] = 0;

        while(!q.empty()){
            int n = q.size();
            while(n--){
                auto front = q.front();
                int node = front.first;
                int wt = front.second;

                q.pop();

                for(const auto &[newNode, newWt] : adjList[node]){
                    if(wt + newWt < dist[newNode]){
                        dist[newNode] = wt+newWt;
                        q.push({newNode, wt + newWt});
                    }
                }
            }
        }

        return dist[n-1] == INT_MAX ? -1 : dist[n-1];
    }
};