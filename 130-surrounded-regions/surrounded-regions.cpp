class Solution {
private:
    void dfs(vector<vector<char>>& board, vector<vector<int>>& visited, int i, int j) {
        int n = board.size();
        int m = board[0].size();

        // 'X' should not be traversed...
        if(i<0 || i>=n || j<0 || j>=m || board[i][j] == 'X' || visited[i][j]) {
            return;
        }

        visited[i][j] = 1;

        int delRow[4] = {0,0,-1,1};
        int delCol[4] = {-1,1,0,0};
    
        for(int idx=0; idx<4; idx++) {
            int row = i + delRow[idx];
            int col = j + delCol[idx];

            dfs(board, visited, row, col);
        }
    }

public:
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();
        vector<vector<int > > visited(n, vector<int>(m,0));

        // check for left edges
        for(int i=0; i<n; i++) {
            if(board[i][0] == 'O' && !visited[i][0]) {
                dfs(board, visited, i, 0);
            }
        }

        // check for top edges
        for(int j=0; j<m; j++) {
            if(board[0][j] == 'O' && !visited[0][j]) {
                dfs(board, visited, 0, j);
            }
        }

        // check for right edges
        for(int i=0; i<n; i++) {
            if(board[i][m-1] == 'O' && !visited[i][m-1]) {
                dfs(board, visited, i, m-1);
            }
        }

        // check for bottom edges
        for(int j=0; j<m; j++) {
            if(board[n-1][j] == 'O' && !visited[n-1][j]) {
                dfs(board, visited, n-1, j);
            }
        }

        // now check if there are still 'O' post dfs
        // means 'O' not visited
        // if yes then convert them to 'X'
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(board[i][j] == 'O' && !visited[i][j]) {
                    board[i][j] = 'X';
                }
            }
        }
    }
};