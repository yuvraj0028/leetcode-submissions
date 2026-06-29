class Solution {
private:
    void dfs(vector<vector<int>>& grid, int i, int j, int n, int m, int &area) {
        if(i<0 || i>=n || j<0 || j>=m || !grid[i][j]) {
            return;
        }

        grid[i][j] = 0;
        area++;

        int delRow[4] = {0,-1,0,1};
        int delCol[4] = {1,0,-1,0};

        for(int idx=0; idx<4; idx++) {
            int row = i + delRow[idx];
            int col = j + delCol[idx];

            dfs(grid, row, col, n, m, area);
        }
    }

public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int maxArea = 0;
        int n = grid.size();
        int m = grid[0].size();

        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(grid[i][j]) {
                    int area = 0;
                    dfs(grid, i, j, n, m, area);
                    maxArea = max(maxArea, area);
                }
            }
        }

        return maxArea;
    }
};