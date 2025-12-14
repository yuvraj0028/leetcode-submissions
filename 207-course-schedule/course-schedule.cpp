class Solution {
private:
    bool dfs(
        unordered_map<int, vector<int > > &adjList,
        unordered_map<int, bool> &visited,
        unordered_map<int, bool> &dfsVisited,
        int node
    ) {

        visited[node] = 1;
        dfsVisited[node] = 1;

        for(const auto &i: adjList[node]){
            if(!visited[i]){
                if(dfs(adjList, visited, dfsVisited, i)){
                    return true;
                }
            }
            if(dfsVisited[i]){
                return true;
            }
        }

        dfsVisited[node] = 0;
        return false;
    }

public:
    bool canFinish(int numCourses, vector<vector<int>>& preq) {
        int n = preq.size();
        unordered_map<int, vector<int > > adjList;
        unordered_map<int, bool> visited, dfsVisited;
        for(int i = 0; i<n; i++){
            int u = preq[i][0];
            int v = preq[i][1];

            adjList[u].push_back(v);
        }

        for(int i = 0; i<numCourses; i++){
            if(!visited[i]){
                if(dfs(adjList, visited, dfsVisited, i)){
                    return false;
                }
            }
        }

        return true;
    }
};