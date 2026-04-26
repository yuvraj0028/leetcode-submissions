class Solution {
private:
    bool dfs(vector<vector<char>>& grid, vector<vector<bool>>& visited, int i, int j, int originI, int originJ, char target) {
        int m = grid.size();
        int n = grid[0].size();
    
        int delRow[4] = {1,0,-1,0};
        int delCol[4] = {0,-1,0,1};
        visited[i][j] = true;

        for(int index = 0; index<4; index++) {
            int delI = i + delRow[index];
            int delJ = j + delCol[index];

            if(delI >= 0 && delI < m && delJ >= 0 && delJ < n && grid[delI][delJ] == target) {
                if(visited[delI][delJ]) {
                    if(delI != originI || delJ != originJ) return true;
                } else {
                    if(dfs(grid, visited, delI, delJ, i, j, target)) return true;
                }
            }
        }

        return false;
    }

public:
    bool containsCycle(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n,false));

        for(int i = 0; i<m; i++) {
            for(int j = 0; j<n; j++) {
                if(visited[i][j]) continue;
                if(dfs(grid, visited, i, j, -1, -1, grid[i][j])) {
                    return true;
                }
            }
        }

        return false;
    }
};