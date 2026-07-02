class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int n = grid.size(), m = grid[0].size();

        // maintain max health per cell
        vector<vector<int > > maxHealth(n, vector<int>(m, -1));
        // {row, col}
        deque<pair<int,int > > coords;

        int startingHealth = health - grid[0][0];
        if(startingHealth <= 0) return false;

        maxHealth[0][0] = startingHealth;
        coords.push_front({0,0});
    
        int delRow[4] = {0,0,-1,1};
        int delCol[4] = {-1,1,0,0};

        while(!coords.empty()) {
            auto [r, c] = coords.front();
            coords.pop_front();

            if(r == n-1 && c == m-1) {
                return maxHealth[r][c] >= 1;
            }

            for(int i = 0; i<4; i++) {
                int row = r + delRow[i];
                int col = c + delCol[i];

                if(row >= 0 && row<n && col >= 0 && col < m) {
                    int nextHealth = maxHealth[r][c] - grid[row][col];
                    if(nextHealth > maxHealth[row][col]) {
                        maxHealth[row][col] = nextHealth;

                        if(grid[row][col]) {
                            coords.push_back({row,col});
                        } else {
                            coords.push_front({row,col});
                        }
                    }
                }
            }
        }

        return false;
    }
};