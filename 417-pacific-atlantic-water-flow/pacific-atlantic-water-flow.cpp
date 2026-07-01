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

        // bfs teaversals
        while(!q.empty()) {
            auto [r,c] = q.front();
            q.pop();

            for(int i = 0; i<4; i++) {
                // finding neighbours
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
                    // valid neighbour -> curr height > previous height
                    // store 2 for atlantic and 1 for pacific
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

        // {row, col} -> pacific queue
        queue<pair<int,int>> pacificQueue;
        // aux matrix to track the flow (1->pacific, 2->atlantic, 3->both, INT_MAX->None)
        vector<vector<int>> flow(n, vector<int>(m,INT_MAX));
        // coords check for pacific & atlantic
        vector<vector<int>> visited(n, vector<int>(m,0));
        // result DS -> stores coordinates(i,j) of value "3" from flow matrix
        vector<vector<int>> coords;

        // traverse for pacific
        // fill left edges
        for(int row = 0; row<n; row++) {
            visited[row][0] = 1;
            pacificQueue.push({row,0});
            // prefill ocean touching cells
            flow[row][0] = 1;
        }

        // fill top edges
        for(int col = 1; col<m; col++) {
            visited[0][col] = 1;
            pacificQueue.push({0,col});
            // prefill ocean touching cells
            flow[0][col] = 1;

        }
        // bfs call for pacific
        bfs(pacificQueue, heights, flow, visited, n, m, 1);

        // traverse of atlantic
        // {row, col} -> atlantic queue
        queue<pair<int,int>> atlanticQueue;
        // clearing visited array for atlantic traversal
        visited.assign(n, vector<int>(m,0));

        // fill right edge
        for(int row = 0; row<n; row++) {
            visited[row][m-1] = 1;
            atlanticQueue.push({row,m-1});
            // prefill ocean touching cells
            flow[row][m-1] = flow[row][m-1] == INT_MAX ? 2 : 3;

        }

        // fill bottom edge
        for(int col = 0; col<m-1; col++) {
            visited[n-1][col] = 1;
            atlanticQueue.push({n-1,col});
            // prefill ocean touching cells
            flow[n-1][col] = flow[n-1][col] == INT_MAX ? 2 : 3;
        }

        // bfs call for atlantic
        bfs(atlanticQueue, heights, flow, visited, n, m, 0);

        // store the common water flowing cells (3)
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