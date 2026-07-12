class Solution {
private:
    bool dfs(unordered_map<int, vector<int > > &adjList,  int src, int dest, vector<bool> &visited) {
        visited[src] = 1;

        if(src == dest) return true;

        for(const auto &node: adjList[src]) {
            if(visited[node]) continue;

            if(dfs(adjList, node, dest, visited)) {
                return true;
            }
        }

        return false;
    }

public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        unordered_map<int, vector<int > > adjList;

        for(const auto &edge: edges) {
            int u = edge[0];
            int v = edge[1];

            vector<bool> visited(edges.size(),0);
            if(adjList.find(u) != adjList.end() && adjList.find(v) != adjList.end() && dfs(adjList, u, v, visited)) {
                return edge;
            }

            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }

        return {};
    }
};