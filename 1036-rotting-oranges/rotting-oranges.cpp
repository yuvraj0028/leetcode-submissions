class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int time = 0;
        int delRow[] = {-1,1,0,0};
        int delCol[] = {0,0,-1,1};
        vector<vector<int>>& visited = grid;
        queue<pair<int,pair<int,int > > > q;

        for(int i = 0; i<grid.size(); i++){
            for(int j = 0;j<grid[0].size(); j++){
                if(grid[i][j] == 2){
                    q.push({0,{i,j}});
                }
            }
        }

        while(!q.empty()){
            time = q.front().first;
            int i = q.front().second.first;
            int j = q.front().second.second;

            q.pop();
            
            for(int index = 0; index<4; index++){
                int nRow = i + delRow[index];
                int nCol = j + delCol[index];
                
                if(nRow >= 0 && nRow<grid.size() && nCol>=0 && nCol<grid[0].size() && visited[nRow][nCol] == 1){
                    q.push({time+1, {nRow, nCol}});
                    visited[nRow][nCol] = 2;
                }
            }
        }

        for(int i= 0; i<grid.size(); i++){
            for(int j = 0;j<grid[0].size(); j++){
                if(visited[i][j] == 1){
                    return -1;
                }
            }
        }

        return time;
    }
};