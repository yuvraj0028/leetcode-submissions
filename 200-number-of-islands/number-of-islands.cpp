class Solution {
private:
    void dfs(vector<vector<char>>& grid, int i, int j){
        if(i>=0 && i<grid.size() && j>=0 && j<grid[0].size() && grid[i][j] == '1'){
            grid[i][j] = '0';
            
            int delI[] = {0,1,0,-1};
            int delJ[] = {1,0,-1,0};

            for(int index = 0; index<4; index++){
                dfs(grid, i + delI[index], j + delJ[index]);
            }
        }
    }

public:
    int numIslands(vector<vector<char>>& grid) {
        int cnt = 0;
        for(int i = 0;i<grid.size(); i++){
            for(int j = 0;j<grid[0].size(); j++){
                if(grid[i][j] == '1'){
                    cnt++;
                    dfs(grid,i,j);
                }
            }
        }
        return cnt;
    }
};