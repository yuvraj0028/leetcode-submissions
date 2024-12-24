class Solution {
private:
    int findHops(unordered_map<int, vector<int > > &adj, int n){
        int last = 0, hops = 0;

        queue<int> q;
        q.push(last);

        vector<bool> vis(n,false);
        vis[last] = true;
        
        while(!q.empty()){
            int size = q.size();

            for(int i = 0;i<size; i++){
                last = q.front();
                q.pop();

                for(const int &node : adj[last]){
                    if(!vis[node]){
                        q.push(node);
                        vis[node] = true;
                    }
                }
            }
        }

        q.push(last);

        for(int i = 0;i<n;i++){
            vis[i] = false;
        }

        while(!q.empty()){
            int size = q.size();

            for(int i = 0;i<size; i++){
                int parent = q.front();
                q.pop();

                for(const int &node : adj[parent]){
                    if(!vis[node]){
                        q.push(node);
                        vis[node] = true;
                    }
                }
            }
            hops++;
        }

        return hops-1;
    }

    int findDiameter(vector<vector<int>>& edges){
        int n = edges.size();

        if(n==0) return 0;

        unordered_map<int, vector<int > > adj;
        unordered_set<int> edge;

        for(int i = 0; i<n; i++){
            int u = edges[i][0];
            int v = edges[i][1];

            adj[u].push_back(v);
            adj[v].push_back(u);

            edge.insert(u);
            edge.insert(v);
        }

        return findHops(adj, edge.size());
    }
public:
    int minimumDiameterAfterMerge(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        int dia1 = findDiameter(edges1);
        int dia2 = findDiameter(edges2);

        int sum = 1 + (dia1 + 1)/2 + (dia2 + 1)/2;

        return max({sum, dia1,dia2});
    }
};