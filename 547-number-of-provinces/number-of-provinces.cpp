class Solution {
private:
    void dfs(unordered_map<int, vector<int > > &adjList, unordered_map<int, bool> &visited, int node) {
        visited[node] = 1;

        for(const auto &nextNode : adjList[node]) {
            if(!visited[nextNode]) {
                dfs(adjList, visited, nextNode);
            }
        }
    }

public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int cnt = 0;
        int n = isConnected.size();
        unordered_map<int, bool> visited;
        unordered_map<int, vector<int > > adjList;


        for(int i = 0; i<n; i++) {
            for(int j = 0; j<n; j++) {
                if(isConnected[i][j]) {
                    adjList[i].push_back(j);
                }
            }
        }

        for(const auto [k,v] : adjList) {
            for(const auto node: adjList[k]) {
                if(!visited[node]) {
                    cnt++;
                    dfs(adjList, visited, node);
                }
            }
        }

        return cnt;
    }
};