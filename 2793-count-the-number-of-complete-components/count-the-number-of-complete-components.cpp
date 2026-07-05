class Solution {
private:
    void dfs(unordered_map<int, vector<int > > &adjList, vector<bool> &visited, int node, int &nodes, int &edges) {
        visited[node] = 1;
        edges+=adjList[node].size();
        nodes++;
        for(const auto &nextNode: adjList[node]) {
            if(!visited[nextNode]) {
                dfs(adjList, visited, nextNode, nodes, edges);
            }
        }
    }

public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        unordered_map<int, vector<int > > adjList;
        vector<bool> visited(n, 0);
        int cnt = 0;

        for(const auto &edge: edges) {
            int u = edge[0];
            int v = edge[1];

            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }

        for(int i = 0; i<n; i++) {
            if(!visited[i]) {
                int edges = 0;
                int nodes = 0;
                dfs(adjList, visited, i, nodes, edges);

                if(edges == (nodes*(nodes-1))) {
                    cnt++;
                }
            }
        }

        return cnt;
    }
};