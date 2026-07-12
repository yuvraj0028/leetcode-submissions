// Optimized Solution -> DSU (Solution 2) 
class DisjointSet {
private:
    vector<int> rank, parent;
public:
    DisjointSet(int n) {
        rank.resize(n+1);
        parent.resize(n+1);

        for(int i = 0; i<=n; i++) {
            rank[i] = 0;
            parent[i] = i;
        }
    }

    int findParent(int node) {
        if(parent[node] == node) return node;

        return parent[node] = findParent(parent[node]);
    }

    bool findByRank(int u, int v) {
        int ultimateParentU = findParent(u);
        int ultimateParentV = findParent(v);

        if(ultimateParentU == ultimateParentV) {
            return true;
        }

        if(rank[ultimateParentU] > rank[ultimateParentV]) {
            parent[ultimateParentV] = ultimateParentU;
        } else if (rank[ultimateParentU] < rank[ultimateParentV]) {
            parent[ultimateParentU] = ultimateParentV;
        } else {
            parent[ultimateParentV] = ultimateParentU;
            rank[ultimateParentU]++;
        }

        return false;
    }
};

class Solution {
private:
    // Solution 1 -> Brute force
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
        
        /*
        Brute Force Solution(1)
        
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
        */

        // Optimized solution using DSU (Solution 2)

        DisjointSet disjointSet(edges.size());
        for(const auto &edge: edges) {
            int u = edge[0];
            int v = edge[1];

            if(disjointSet.findByRank(u,v)) {
                return edge;
            }
        }

        return {};
    }
};