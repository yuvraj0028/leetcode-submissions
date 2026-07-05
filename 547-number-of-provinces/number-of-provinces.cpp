class Solution {
private:
    void dfs(vector<vector<int>>& isConnected, vector<bool>& visited, int node) {
        int n = isConnected.size();
        visited[node] = 1;

        for(int i = 0; i<n; i++) {
            if(!visited[i] && isConnected[node][i]) {
                dfs(isConnected, visited, i);
            }
        }
    }

public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int cnt = 0;
        int n = isConnected.size();
        vector<bool> visited(n, 0);


        for(int i = 0; i<n; i++) {
            if(!visited[i]) {
                cnt++;
                dfs(isConnected, visited, i);
            }
        }

        return cnt;
    }
};