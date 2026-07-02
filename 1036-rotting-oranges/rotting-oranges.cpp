class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int totalTime = 0;

        vector<vector<bool > > visited(n, vector<bool>(m,0));
        // {time, {row, col}}
        queue<pair<int, pair<int,int > > > q;
    
        for(int i = 0; i<n; i++) {
            for(int j = 0; j<m; j++) {
                if(grid[i][j] == 2) {
                    visited[i][j] = 1;
                    q.push({0, {i,j}});
                }
            }
        }

        int delRow[4] = {0,0,-1,1};
        int delCol[4] = {-1,1,0,0};
    
        while(!q.empty()) {
            auto [time, coords] = q.front();
            auto [r, c] = coords;
            totalTime = max(time, totalTime);
            q.pop();

            for(int i=0; i<4; i++) {
                int row = r + delRow[i];
                int col = c + delCol[i];
            
                if(row>=0 && row<n && col>=0 && col<m && !visited[row][col] && grid[row][col] == 1) {
                    visited[row][col] = 1;
                    q.push({time+1, {row, col}});
                }
            }
        }

        for(int i = 0; i<n; i++) {
            for(int j = 0; j<m; j++) {
                if(grid[i][j] == 1 && !visited[i][j]) {
                    return -1;
                }
            }
        }

        return totalTime;
    }
};