class Solution {
private:
    void dfs(vector<vector<char>>& grid, vector<vector<bool>>& visited, int i, int j) {
        if(i<0 || i>=grid.size() || j<0 || j>=grid[0].size() || grid[i][j]=='0' || visited[i][j]) {
            return;
        }

        visited[i][j] = 1;
        int delRow[4] = {0,-1,0,1};
        int delCol[4] = {1,0,-1,0};

        for(int idx=0; idx<4; idx++) {
            int row = i + delRow[idx];
            int col = j + delCol[idx];

            dfs(grid, visited, row, col);
        }
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int island = 0;
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>> visited(n, vector<bool>(m, 0));

        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(!visited[i][j] && grid[i][j] == '1') {
                    island++;
                    dfs(grid, visited, i, j);
                }
            }
        }

        return island;
    }
};