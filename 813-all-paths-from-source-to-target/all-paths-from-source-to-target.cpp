class Solution {
private:
    vector<int> path;
    vector<vector<int > > paths;
    int target;
    void dfs(vector<vector<int>>& graph, int src = 0){
        path.push_back(src);
        if(src == target){
            paths.push_back(path);
        }

        for(const auto &node : graph[src]){
            dfs(graph, node);
        }

        path.pop_back();
    }
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        target = graph.size()-1;
        dfs(graph);
        return paths;
    }
};