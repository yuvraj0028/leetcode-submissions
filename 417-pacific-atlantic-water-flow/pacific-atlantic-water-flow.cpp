class Solution {
private:
    void bfs(
        queue<pair<int,int>> &q,
        vector<vector<int>>& heights, 
        vector<vector<int>> &flow, 
        vector<vector<int>> &visited,
        int n, 
        int m, 
        bool isPacific = 0
    ) {
        
        int delRow[4] = {0,0,-1,1};
        int delCol[4] = {-1,1,0,0};

        while(!q.empty()) {
            auto [r,c] = q.front();
            q.pop();

            for(int i = 0; i<4; i++) {
                int row = r + delRow[i];
                int col = c + delCol[i];

                if(
                    row >= 0 && 
                    row<n && 
                    col >= 0 && 
                    col < m && 
                    !visited[row][col] && 
                    heights[row][col] >= heights[r][c]
                ) {
                    visited[row][col] = 1;
                    if(flow[row][col] == INT_MAX) {
                        flow[row][col] = isPacific ? 1 : 2;
                    } else if (flow[row][col]){
                        flow[row][col] = 3;
                    }

                    q.push({row,col});
                }
            }
        }
    }

public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();

        queue<pair<int,int>> pacificQueue;
        vector<vector<int>> flow(n, vector<int>(m,INT_MAX));
        vector<vector<int>> visited(n, vector<int>(m,0));
        vector<vector<int>> coords;

        // traverse for pacific
        for(int row = 0; row<n; row++) {
            visited[row][0] = 1;
            pacificQueue.push({row,0});
            flow[row][0] = flow[row][0] == INT_MAX ? 1 : 2;
        }

        for(int col = 1; col<m; col++) {
            visited[0][col] = 1;
            pacificQueue.push({0,col});
            flow[0][col] = flow[0][col] == INT_MAX ? 1 : 3;

        }

        bfs(pacificQueue, heights, flow, visited, n, m, 1);


        // traverse of atlantic
        queue<pair<int,int>> atlanticQueue;
        visited.assign(n, vector<int>(m,0));

        for(int row = 0; row<n; row++) {
            visited[row][m-1] = 1;
            atlanticQueue.push({row,m-1});
            flow[row][m-1] = flow[row][m-1] == INT_MAX ? 2 : 3;

        }

        for(int col = 0; col<m-1; col++) {
            visited[n-1][col] = 1;
            atlanticQueue.push({n-1,col});
            flow[n-1][col] = flow[n-1][col] == INT_MAX ? 2 : 3;
        }

        bfs(atlanticQueue, heights, flow, visited, n, m, 0);

        for(int i =0; i<n; i++) {
            for(int j =0;j<m; j++) {
                if(flow[i][j] == 3) {
                    coords.push_back({i,j});
                }
            }
        }

        return coords;
    }
};