class Solution {
public:
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int delRow[4] = {0,0,-1,1};
        int delCol[4] = {-1,1,0,0};

        vector<vector<int > > dist(n, vector<int>(m,0));
        vector<vector<int > > visited(n, vector<int>(m,0));

        // {row, col}
        queue<pair<int,int>> q;

        // {safeness, {row,col}}
        priority_queue<pair<int, pair<int,int > > > pq;

        for(int i = 0; i<n; i++) {
            for(int j = 0; j<m; j++) {
                if(grid[i][j]) {
                    q.push({i,j});
                    visited[i][j] = 1;
                }
            }
        }

        while(!q.empty()) {
            auto [r,c] = q.front();
            q.pop();

            for(int i=0; i<4; i++) {
                int row = r + delRow[i];
                int col = c + delCol[i];

                if(row>=0 && row<n && col>=0 && col<m && !visited[row][col]) {
                    dist[row][col] = dist[r][c] + 1;
                    visited[row][col] = 1;
                    q.push({row,col});
                }
            }
        }

        pq.push({dist[0][0], {0,0}});
        visited.assign(n, vector<int>(m,0));
        visited[0][0] = 1;

        while(!pq.empty()) {
            auto [safeness, coord] = pq.top();
            auto [r, c] = coord;
            pq.pop();

            if(r == n-1 && c == m-1) return safeness;

            for(int i=0; i<4; i++) {
                int row = r + delRow[i];
                int col = c + delCol[i];

                if(row>=0 && row<n && col>=0 && col<m && !visited[row][col]) {
                    visited[row][col] = 1;
                    int nextSafeness = min(safeness, dist[row][col]);
                    pq.push({nextSafeness, {row,col}});
                }
            }
        }

        return 0;
    }
};