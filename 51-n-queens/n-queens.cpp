class Solution {
private:
    bool isSafe(int row, int col, vector<string> &board){
        int x = row, y = col;
        while(x>=0){
            if(board[x][y] == 'Q'){
                return false;
            }
            x--;
        }

        x = row; y = col;
        while(x>=0 && y>=0){
            if(board[x][y] == 'Q'){
                return false;
            }
            x--;
            y--;
        }

        x = row; y=col
        ;
        while(x>=0 && y<board.size()){
            if(board[x][y] == 'Q'){
                return false;
            }
            x--;
            y++;
        }
        return true;
    }

    void solve(int row, vector<string> &board, vector<vector<string > > &ans){
        if(row==board.size()){
            ans.push_back(board);
            return;
        }

        for(int col = 0; col<board.size(); col++){
            if(isSafe(row,col,board)){
                board[row][col] = 'Q';
                solve(row+1,board,ans);
                board[row][col] = '.';
            }
        }
    }
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n, string(n,'.'));
        vector<vector<string > > ans;

        solve(0, board, ans);
        return ans;
    }
};